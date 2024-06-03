#include "Cluster.h"
#include <iostream>
using namespace std;

Cluster::~Cluster()
{
    delete[] content;
}

FileTypeEnum Cluster::GetFileType()
{
	if (content[0] == 0x25 && content[1] == 0x50 &&
	 content[2] == 0x44 && content[3] == 0x46) {
		return  FileTypeEnum::Pdf;
	}
	else if (content[0] == 0x4D && content[1] == 0x5A) {
		return  FileTypeEnum::Exe;
    }
	else if (content[0] == 0xFF && content[1] == 0xD8) {
        return  FileTypeEnum::Jpeg;
	}
	else if (content[0] == 0x89 && content[1] == 0x50 &&
	 content[2] == 0x4E && content[3] == 0x47 && content[4] == 0x0D &&
	  content[5] == 0x0A && content[6] == 0x1A && content[7] == 0x0A) {
		return  FileTypeEnum::Png;
	}
	else if (content[0] == 0x50 && content[1] == 0x4B && content[2] == 0x03 &&
	 content[3] == 0x04 && content[4] == 0x14 && content[5] == 0x00 &&
	  content[6] == 0x06 && content[7] == 0x00) {
		return  FileTypeEnum::Docx;
	}
	else if (content[0] == 0xD0 && content[1] == 0xCF && content[2] == 0x11 &&
	 content[3] == 0xE0 && content[4] == 0xA1 && content[5] == 0xB1 &&
	  content[6] == 0x1A && content[7] == 0xE1) {
		return  FileTypeEnum::Doc;
	}
	return FileTypeEnum::Underfind;
}

Cluster::Cluster(BYTE* data, unsigned int num, unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
    clusterNum = num;
}
void Cluster::SetContent(BYTE* data,unsigned int ClusterSize)
{
    content = new BYTE[ClusterSize];
    std::memcpy(content, data, sizeof(BYTE) * ClusterSize);
}
