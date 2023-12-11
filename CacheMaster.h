#ifndef CACHE_MASTER
#define CACHE_MASTER
#pragma once

#include <vector>
#include "CacheController.h"

class CacheMaster
{
private:
	vector<CacheController> Caches;
	unsigned int ToatalAccessTime = 0;
	unsigned int TotalNumberOfAccess = 0;
public:
	CacheMaster(vector<unsigned int> cacheSize, vector<unsigned int> blockSize, vector<unsigned int> accessTime);
	void readFile(string filename);
};


#endif // !CACHE_MASTER
