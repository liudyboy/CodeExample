## run
First we should assign variable `CPLUS_INCLUDE_PATH` to this project path. Such as
```
export CPLUS_INCLUDE_PATH = ~/cython_warp_c++_client
```

run c++ server
```
bazel run //:server
```

run python client
```
bazel run //:py_client
```

## Observations
We can just run
```
bazel build //:client_lib
```
It can generate a shared library in `bazel-bin`. Then we can import the shared library as follows:
```python
from py_greeter_client import PyClient
```
