#include "CacheMaster.h"
#include <cmath>
#include <vector>

int main() 
{
    unsigned int levels;
    cout << "Enter the number of cache levels: ";
    cin >> levels;
    while (levels < 1) {
        cout << "Error! the number of levels must be positive\n";
        cout << "Enter the number of cache levels: ";
        cin >> levels;
    }
    vector<unsigned int> cacheSizes, blockSizes, accessTimes;
    for (int i = 0; i < levels; i++) {
        cout << "For the level " << i + 1 << " Cache:\n";
        unsigned int cacheSize, blockSize, accessTime;
        cout << "Enter the size of the cache in bytes: ";
        cin >> cacheSize;
        while (ceil(log2(cacheSize)) != floor(log2(cacheSize)))
        {
            cout << "Error! Cache size must be a power of 2" << endl;
            cout << "Enter the size of the cache in bytes: ";
            cin >> cacheSize;
        }
        cout << endl;
        cout << "Enter the block size in bytes: ";
        cin >> blockSize;
        while (ceil(log2(blockSize)) != floor(log2(blockSize)))
        {
            cout << "Error! Block size must be a power of 2" << endl;
            cout << "Enter the block size in bytes: ";
            cin >> blockSize;
        }
        cout << endl;
        cout << "Enter the number of access cycles needed to access the cache (An integer from 1 to 10): ";
        cin >> accessTime;
        while (accessTime < 1 || accessTime > 10)
        {
            cout << "Error! Number of access cycles must be between 1 and 10" << endl;
            cout << "Enter the number of access cycles needed to access the cache (An integer from 1 to 10): ";
            cin >> accessTime;
        }
        cacheSizes.push_back(cacheSize);
        blockSizes.push_back(blockSize);
        accessTimes.push_back(accessTime);
    }

    string filename = "test.txt";

    CacheMaster cacheMaster(cacheSizes, blockSizes, accessTimes);
    cacheMaster.readFile(filename);

    return 0;
}
