from libcpp.string cimport string

cdef extern from "greeter_client.cc":
  pass

cdef extern from "greeter_client.h":
  cdef cppclass GreeterClient:
    GreeterClient() except +
    GreeterClient(string target) except +
    string SayHello(string user)
