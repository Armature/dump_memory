# Memory dump example
## Dependencies
* Python 3.8 or later
* Tensorflow
* G++ 6 or later
## How To Reproduce
* `python test.py`: Loads the Tensorflow framework to memory, waits in a infinite while loop.
* Obtain python process' pid through `ps -a`.
* `sudo sh dump_pid.sh [pid] ./dump`: Dumps allocated memory of given process [pid] to `./dump`, excluding `*.so` memory mapped shared libraries and empty memory ranges.
* `g++ -std=c++17 -o read_dump read_dump.cpp`: Compile the C++ source to read dump files.
* `./read_dump ./dump ./result.txt [data width]`: Reads the given dump files in `./dump` and exports results to `./results.txt`. One read is executed in [data width] granularity, and values with all zeros are excluded in the result file.
## Results
