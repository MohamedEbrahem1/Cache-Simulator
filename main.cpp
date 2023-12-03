#include "CacheController.h"

int main() 
{
    unsigned int cacheSize, blockSize, accessTime;

    cout << "Enter the size of the cache in bytes: ";
    cin >> cacheSize;
    while(cacheSize % 2 != 0)
    {
        cout << "Error! Cache size must be a power of 2" << endl;
        cout << "Enter the size of the cache in bytes: ";
        cin >> cacheSize;
    }
    cout << endl;
    cout << "Enter the block size in bytes: ";
    cin >> blockSize;
    while(blockSize % 2 != 0)
    {
        cout << "Error! Block size must be a power of 2" << endl;
        cout << "Enter the block size in bytes: ";
        cin >> blockSize;
    }
    cout << endl;
    cout << "Enter the number of access cycles needed to access the cache (An integer from 1 to 10): ";
    cin >> accessTime;
    while(accessTime < 1 || accessTime > 10)
    {
        cout << "Error! Number of access cycles must be between 1 and 10" << endl;
        cout << "Enter the number of access cycles needed to access the cache (An integer from 1 to 10): ";
        cin >> accessTime;
    }

    string filename = "test.txt";

    CacheController cacheController(cacheSize, blockSize, accessTime);
    cacheController.processMemoryAccess(filename);

    return 0;
}
