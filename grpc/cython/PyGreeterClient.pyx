# distutils: language = c++
# language_level=3
# cython: c_string_type=unicode, c_string_encoding=utf8

import cython
from libcpp.string cimport string

cdef extern from "<grpcpp/grpcpp.h>" namespace "grpc":
    cdef cppclass Channel:
        pass

# cdef extern from "helloworld.grpc.pb.h" namespace "helloworld":
#     cdef cppclass Greeter:
#         # cdef cppclass Stub:
#         #     pass
#         # cdef cppclass NewStub:
#         #     pass
#         pass



cdef extern from "greeter_client.h":
    cdef cppclass GreeterClient:
        GreeterClient(string) except +
        string SayHello(const string)


cdef class PyGreeterClient:
    cdef GreeterClient *client

    def __cinit__(self, bytes target):
        cdef string s = target
        self.client = new GreeterClient(s)

    def SayHello(self, bytes say):
        cdef string s = say
        s = self.client.SayHello(s)
        return str(s.c_str())
