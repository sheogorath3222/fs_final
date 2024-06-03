#include "MyFSC.h"
#include "FileSystemCreator.h"
#include "NTFS.h"
#include "HFS+.h"
#include <stdexcept>

FS* MyFSC::CreateFileSystem(FSEnum fsType, LPCWSTR device)
{
	switch (fsType) {
	case FSEnum::NTFS: {
		NTFS* fs = new NTFS();
		fs->Init(device);
		return fs;
	}
	case FSEnum::HFSp: {
		HFSP* fs = new HFSP();
		fs->Init(device);
		return fs;
	}
	default:
		throw std::invalid_argument("Set FilePointer error");
		return NULL;
	}
}
