#include "HFS+.h"
#include <iostream>
#include "windows.h"

using namespace std;

bool HFSP::ReadClusterSize() {
    BYTE sector[512];
    DWORD bytesRead;
    DWORD bytesToRead = sizeof(sector);

    LARGE_INTEGER sectorSizeOffset{};
    sectorSizeOffset.QuadPart = 1024;

    if (!SetFilePointerEx(fileHandler, sectorSizeOffset, NULL, FILE_BEGIN)) {
        throw std::invalid_argument("Set FilePointer error");
        CloseHandle(fileHandler);
        return false;
    }
    if (!ReadFile(fileHandler, sector, bytesToRead, &bytesRead, NULL)) {
        throw std::invalid_argument("ReadFile error");
        CloseHandle(fileHandler);
        return false;
    }

    BootRecord *pBootRecord = reinterpret_cast<BootRecord *>(sector);
    clusterSize = pBootRecord->clusterSize;
    clusterCount = pBootRecord->clusterCount;
    return true;
}
