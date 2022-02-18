# 文件和使用说明

## 文件说明

- `greeter_server.cc`: greeter的Server模块，含GreeterServer类和main函数
- `greeter_client.h`, `greeter_client.cc`: greeter的Client模块
- `greeter_client_main`: 调用greeter_client中的接口的main函数
- `helloworld.proto`: gRPC协议定义
- `Makefile`: 构建整个项目
- `PyGreeterClient.pyx`: Cython调用
- `build.py`: 构建cython模块, 使用之前有一些依赖, 请使用make通过Makefile构建
- `greeter_client_cython_call.py`: 使用Cython模块的client
- `greeter_client.py`: 直接使用python的client代码

## 使用说明

按照为Python client安装`python -m pip install grpcio`, 为grpc c++安装官网进行构建安装`https://grpc.io/docs/languages/cpp/quickstart/#build-and-install-grpc-and-protocol-buffers`

使用前请在Makefile中修改grpc c++安装位置, 默认为`GPRC_PATH = /home/zombie/.local`, 同时修改build.py中的`grpc_path`

使用`make`构建所有程序, 使用`./greeter_server`打开服务器, 使用`./greeter_client_main`使用C++构建的客户端, 使用`python3 ./greeter_client_cython_call.py`使用cython类构建的客户端, 使用`python3 greeter_client.py`使用python直接和c++ server通讯.
