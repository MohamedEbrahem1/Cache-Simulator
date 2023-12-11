#include "CacheController.h"

CacheController::CacheController(unsigned int cacheSize, unsigned int blockSize, unsigned int accessTime)
    : sizeOfCache(cacheSize), lineBlockSize(blockSize), accessTime(accessTime), numberOfAccesses(0), cacheHits(0), cacheMisses(0) 
{
    initializeCache();
}

void CacheController::initializeCache() 
{
    linesCount = sizeOfCache / lineBlockSize;
    indexBits = log2(linesCount);
    offsetBits = log2(lineBlockSize);
    tagBits = 24 - indexBits - offsetBits;

    cacheMemory.resize(linesCount);
    for (auto& cacheLine : cacheMemory) 
    {
        cacheLine.isValid = false;
        cacheLine.tagValue = 0;
    }
}

unsigned int CacheController::getIndex(unsigned int address) 
{
    return (address >> offsetBits) & ((1 << indexBits) - 1);
}

unsigned int CacheController::getTag(unsigned int address) 
{
    return (address >> (indexBits + offsetBits));
}

bool CacheController::processMemoryAddress(unsigned int memoryAddress) 
{
    ++numberOfAccesses;
    bool result;
    unsigned int index = getIndex(memoryAddress);
    unsigned int tag = getTag(memoryAddress);

    if (cacheMemory[index].isValid && cacheMemory[index].tagValue == tag) 
    {
        ++cacheHits;
        cout << "HIT! Data found in cache\n";
        result = true;
    } 
    else 
    {
        ++cacheMisses;
        cout << "MISS! Data not found in cache\n";
        cacheMemory[index].isValid = true;
        cacheMemory[index].tagValue = tag;
        result = false;
    }

    // Display cache state after each access
    for (unsigned int i = 0; i < linesCount; ++i) 
    {
        cout << "Line " << i << ": Valid = " << cacheMemory[i].isValid << " Tag = " << cacheMemory[i].tagValue << endl;
    }

    double hitRate = double(cacheHits) / numberOfAccesses;
    double missRate = double(cacheMisses) / numberOfAccesses;

    cout << "Total number of accesses of this cache level: " << numberOfAccesses << endl;
    cout << "Local Hit rate: " << fixed << setprecision(2) << hitRate << endl;
    cout << "Local Miss rate: " << fixed << setprecision(2) << missRate << endl;
    cout << endl;
    return result;
}

unsigned int CacheController::getTime()
{
    return accessTime;
}
