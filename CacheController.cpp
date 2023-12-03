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

void CacheController::processMemoryAccess(const string& filename) 
{
    ifstream memoryAccessFile(filename);
    if (!memoryAccessFile.is_open()) 
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    unsigned int memoryAddress;
    while (memoryAccessFile >> memoryAddress) 
    {
        ++numberOfAccesses;
        unsigned int index = getIndex(memoryAddress);
        unsigned int tag = getTag(memoryAddress);

        if (cacheMemory[index].isValid && cacheMemory[index].tagValue == tag) 
        {
            ++cacheHits;
        } 
        else 
        {
            ++cacheMisses;
            cacheMemory[index].isValid = true;
            cacheMemory[index].tagValue = tag;
        }

        // Display cache state after each access
        cout << "Cache Status (After Access " << numberOfAccesses << "):\n";
        for (unsigned int i = 0; i < linesCount; ++i) 
        {
            cout << "Line " << i << ": Valid = " << cacheMemory[i].isValid << " Tag = " << cacheMemory[i].tagValue << endl;
        }

        double hitRate = double(cacheHits) / numberOfAccesses;
        double missRate = double(cacheMisses) / numberOfAccesses;
        double amat = accessTime + (missRate * 100);

        cout << "Total number of accesses: " << numberOfAccesses << endl;
        cout << "Hit rate: " << fixed << setprecision(2) << hitRate << endl;
        cout << "Miss rate: " << fixed << setprecision(2) << missRate << endl;
        cout << "Average Memory Access Time (AMAT): " << fixed << setprecision(2) << amat << " cycles" << endl;
        cout << endl;
    }

    memoryAccessFile.close();
}
