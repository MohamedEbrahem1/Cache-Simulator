# Cache Simulator

This project implements a basic cache simulator in C++ using a class-based approach. The simulator can be configured with different cache sizes, block sizes, and access times. It reads memory access addresses from a file and simulates cache hits and misses, providing statistics such as hit rate, miss rate, and average memory access time.

## Getting Started

### Prerequisites

Make sure you have a C++ compiler installed on your system.

### Build

Compile the project using your preferred C++ compiler. For example:

```bash
g++ main.cpp CacheController.cpp -o cache_simulator
```

### Run

Run the executable with the desired input parameters:

```bash
./cache_simulator
```

Follow the prompts to enter the cache size, block size, and access time. The simulator will then read memory access addresses from the `test.txt` file and display the cache state after each access, along with relevant statistics.

## File Structure

- `CacheController.h` and `CacheController.cpp`: Header and implementation files for the CacheController class, which simulates the cache behavior.

- `main.cpp`: The main driver program to execute the cache simulation.

## Customization

Modify the `test.txt` file to include different memory access addresses for testing various cache scenarios.

## Author

[Mohamed Abdelmagid]

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
