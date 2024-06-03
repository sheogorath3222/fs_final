//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "AnalysThread.h"
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "VirtualTrees.AncestorVCL.hpp"
#include "VirtualTrees.BaseAncestorVCL.hpp"
#include "VirtualTrees.BaseTree.hpp"
#include "VirtualTrees.hpp"
#include "MainUnit.h"
#include "FS.h"
#include "NTFS.h"
#include "windows.h"
#include "IteratorDecorator.h"
#include "FSIteratorDecorator.h"
#include "HFS+.h"
#include "MyFSC.h"
#include "FileSystemCreator.h"
#include "ReadThread.h"
#pragma package(smart_init)
#include <cmath>
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall read_thread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall ReadThread::ReadThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	 FreeOnTerminate = true;

	 UnicodeString tempString = Form1->Edit2->Text;
	 LPCWSTR databasePath = tempString.c_str();

	 AnalysThreadObject = new AnalysThread(false, databasePath);

}
//---------------------------------------------------------------------------
void __fastcall ReadThread::Execute()
{
	while(!Terminated)
	{

		DWORD startTime = GetTickCount();
		FileSystemCreator* fsCreator = new MyFSC;

		UnicodeString tempString = Form1->Edit1->Text;
		logicDisk = tempString.c_str();

		FSEnum fsType = DetectFS(logicDisk);
		Synchronize(UpdateFS);
		FS* fs = fsCreator->CreateFileSystem(fsType, logicDisk);
		if (!fs->Init(logicDisk)) {
			throw  "Can not open logic disk";
		};
		clusterCount = fs->ClusterCount();
		unsigned int clusterSize = fs->ClusterSize();
		FileTypeEnum selectFileType = GetFileType();
		Iterator<Cluster>* it = new FSIteratorDecorator(
			new NTFSIterator(fs),
			selectFileType
		);

		for (it->First();!it->IsDone() && !Terminated;it->Next()) {
			Cluster currentObject = it->GetCurrent();
			clusters += 1;
			AnalysThreadObject->Send(&currentObject);
			AnalysThreadObject->DataReadyEvent->SetEvent();
			while(AnalysThreadObject->DataCopiedEvent->WaitFor(3000) != wrSignaled)
			{ }
			AnalysThreadObject->DataCopiedEvent->ResetEvent();
			Synchronize(UpdateLabel2);
		}

		DWORD endTime = GetTickCount();
		processTime = endTime - startTime ;

		UnicodeString timestr = UnicodeString(processTime);
		Synchronize(UpdateLabel);
        break;
	}

	AnalysThreadObject->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall ReadThread::UpdateLabel()
{
	UnicodeString timestr = UnicodeString(round(static_cast<double>(processTime) / 1000));
	Form1->SearchTimeResultLabel->Caption = timestr;

}
void __fastcall ReadThread::UpdateLabel2()
{
	Form1->CountResultLabel->Caption = clusters;

}

void __fastcall ReadThread::UpdateFS()
{
	Form1->DetectResultLabel->Caption = DetectedFS;
}

FSEnum __fastcall ReadThread::DetectFS(LPCWSTR device) {
    HANDLE fileHandler = CreateFileW(
		device,
		GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

    if (fileHandler == INVALID_HANDLE_VALUE)
    {
        throw std::invalid_argument("Error INVALID_HANDLE_VALUE!");
    }
    DWORD bytesRead;
    BYTE buffer[2048];
	if (!ReadFile(fileHandler, buffer, sizeof(buffer), &bytesRead, nullptr)) {
        throw "Error reading volume\n";
    }

	BYTE ntfsSignature[] = { 0x4E, 0x54, 0x46, 0x53 };
	if (memcmp(buffer + 3, ntfsSignature, sizeof(ntfsSignature)) == 0) {
		DetectedFS = L"NTFS";
		return FSEnum::NTFS;
	}
	BYTE hfsPlusSignature[] = { 0x48, 0x2B, 0x00, 0x04 };
	if (memcmp(buffer + 1024, hfsPlusSignature, sizeof(hfsPlusSignature)) == 0) {
        DetectedFS = L"HFS+";
        return FSEnum::HFSp;
    }
    throw "Cannot detect fs!";
}
FileTypeEnum __fastcall ReadThread::GetFileType()
{
	if(Form1->PdfButton->Checked){
		return  FileTypeEnum::Pdf;
	}
	if(Form1->ExeButton->Checked){
		return  FileTypeEnum::Exe;
	}
	if(Form1->JpegButton->Checked){
		return  FileTypeEnum::Jpeg;
	}
	if(Form1->PngButton->Checked){
		return  FileTypeEnum::Png;
	}
	if(Form1->DocxButton->Checked){
		return  FileTypeEnum::Docx;
	}
	return FileTypeEnum::Doc;
}
