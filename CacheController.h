#ifndef CACHE_CONTROLLER_H
#define CACHE_CONTROLLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct CacheLine 
{
    bool isValid;
    unsigned int tagValue;
};

class CacheController 
{
private:
    vector<CacheLine> cacheMemory;
    unsigned int sizeOfCache;
    unsigned int lineBlockSize;
    unsigned int accessTime;
    unsigned int numberOfAccesses;
    unsigned int cacheHits;
    unsigned int cacheMisses;

    unsigned int linesCount;
    unsigned int indexBits;
    unsigned int offsetBits;
    unsigned int tagBits;

    void initializeCache();

    unsigned int getIndex(unsigned int address);
    unsigned int getTag(unsigned int address);

public:
    CacheController(unsigned int cacheSize, unsigned int blockSize, unsigned int accessTime);
    bool processMemoryAddress(unsigned int);
    unsigned int getTime();
};

#endif
