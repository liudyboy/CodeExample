# distutils: language = c++
# cython: language_level = 3
from greeter_client cimport GreeterClient
from libcpp.string cimport string


cdef class PyClient:
  cdef GreeterClient client
  def SayHello(self, string user):
      reply = self.client.SayHello(user)
      return reply
  def Connect(self, string target):
      self.client.Connect(target)
