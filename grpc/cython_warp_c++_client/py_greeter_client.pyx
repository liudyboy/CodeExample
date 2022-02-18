# distutils: language = c++
# cython: language_level = 3
from greeter_client cimport GreeterClient
from libcpp.string cimport string


cdef class PyClient:
  cdef GreeterClient client
  def __cinit__(self, string target):
      self.client = GreeterClient(target)
  def SayHello(self, string user):
      reply = self.client.SayHello(user)
      return reply



# cdef extern from "greeter_client.h":
# cdef cppclass GreeterClient:
# GreeterClient(string) except +
# string SayHello(const string)


# cdef class PyGreeterClient:
# cdef GreeterClient *client

#     def __cinit__(self, bytes target):
#         cdef string s = target
#         self.client = new GreeterClient(s)

#     def SayHello(self, bytes say):
#         cdef string s = say
#         s = self.client.SayHello(s)
#         return str(s.c_str())
