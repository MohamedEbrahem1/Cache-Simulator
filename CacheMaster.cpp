#include "CacheMaster.h"

CacheMaster::CacheMaster(vector<unsigned int> cacheSize, vector<unsigned int> blockSize, vector<unsigned int> accessTime)
{
	int n = cacheSize.size();
	for (int i = 0; i < n; i++) {
		CacheController c(cacheSize.at(i), blockSize.at(i), accessTime.at(i));
		Caches.push_back(c);
	}
}

void CacheMaster::readFile(string filename)
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
        ++TotalNumberOfAccess;
        int currentTime = 0;
        bool found = false;
        cout << "Cache Status (After Access " << TotalNumberOfAccess << "):\n";
        for (int i = 0; i < Caches.size(); i++) {
            cout << "Level " << i+1 << " Cache:\n";
            currentTime = Caches.at(i).getTime();
            if (Caches.at(i).processMemoryAddress(memoryAddress)) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Data was not found in any cache, it was retireved from memory.\n";
            currentTime += 120;
        }
        cout << "Access Time of this memory address = " << currentTime <<endl;
        ToatalAccessTime += currentTime;
        cout << "Total Access Time = " << ToatalAccessTime << endl;
        double avg = double(ToatalAccessTime) / TotalNumberOfAccess;
        cout << "Average Access Time per address = " << fixed << setprecision(2) << avg << endl;
        cout << endl;
    }

    memoryAccessFile.close();
}
