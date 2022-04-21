from libcpp.string cimport string

cdef extern from "greeter_client.cc":
  pass

cdef extern from "greeter_client.h":
  cdef cppclass GreeterClient:
    GreeterClient() except +
    string SayHello(string user)
    void Connect(string target)


cdef extern from "greeter_client.h":
  cdef cppclass WorkProcess:
    WorkProcess() except +
    string Start(string target, string user)
    void Test(string target, string user, string reply)
    string GetReply()
