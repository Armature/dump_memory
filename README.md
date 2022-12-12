# Memory dump example
## Dependencies
* Python 3.8 or later
* Tensorflow
* G++ 6 or later
## How To Reproduce
* `python test.py`: Loads the Tensorflow framework to memory, waits in a infinite while loop.
* Obtain python process' pid through `ps -a`.
* `sudo sh dump_pid.sh [pid] ./dump`: Dumps allocated memory of given process `[pid]` to `./dump`, excluding `*.so` memory mapped shared libraries and empty memory ranges.
* `g++ -std=c++17 -o read_dump read_dump.cpp`: Compile the C++ source to read dump files.
* `./read_dump ./dump ./result.txt [data width]`: Reads the given dump files in `./dump` and exports results to `./results.txt`. One read analyzes data in `[data width]` granularity, and values with all zeros are excluded in the result file.
## Results
### Result and Source Comparison
Source example from [`tensorflow/tensorflow/python/checkpoint/checkpoint_view.py`](https://github.com/tensorflow/tensorflow/blob/master/tensorflow/python/checkpoint/checkpoint_view.py)
1. Multiple Line Comment

![image](https://user-images.githubusercontent.com/89067533/207003821-e5b4d1ca-5a59-4b92-b382-afadbabd9803.png)

Multiple line comments are not ignored and loaded to memory.

2. Single Line Comment

![image](https://user-images.githubusercontent.com/89067533/207004616-b14f921d-bea8-4783-adf4-a7ee5a614be3.png)

Single Line Comments are ignored and don't appear in memory.

3. Leak Portion

![image](https://user-images.githubusercontent.com/89067533/207005120-3c535b6e-3b2d-42ef-bb87-4011537de2ab.png)

This portion is definitely incorrect since it only considers ASCII alphabet characters, but I think you can get the idea.