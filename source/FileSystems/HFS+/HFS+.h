#pragma once

#include "FS.h"
#include <iostream>
#include "Iterator.h"
#include <cstdint>
#include <cstring>

class HFSP :
        public FS {
private:
#pragma pack(push, 1)
    typedef struct {
        char jumpInstruction[41];
        uint32_t clusterSize;
        uint32_t clusterCount;
    } BootRecord;
#pragma pack(pop)
protected:
    bool ReadClusterSize();

};
