# Memory dump example
## Usage
* `python test.py`: Loads the Tensorflow framework to memory, waits in a infinite while loop.
* `sudo sh dump_pid.sh [pid] [dump directory]`: Dumps allocated memory of given process [pid], excluding `*.so` memory mapped shared libraries and empty memory ranges.
* `g++ -std=c++17 -o read_dump read_dump.cc`: Compile the C++ source to read dump files.
* `./read_dump [dump directory] [value result text file] [data width]`: Reads the given dump files in [dump directory] and exports results to [value result text file]. One read is executed in [data width] granularity, and values with all zeros are excluded in the result file.