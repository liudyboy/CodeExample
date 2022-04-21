# distutils: language = c++
# cython: language_level = 3
from greeter_client cimport GreeterClient
from libcpp.string cimport string
from greeter_client cimport WorkProcess


cdef class PyClient:
  cdef GreeterClient client
  def SayHello(self, string user):
      reply = self.client.SayHello(user)
      return reply
  def Connect(self, string target):
      self.client.Connect(target)

cdef class PyWorkProcess:
  cdef WorkProcess work_process
  def Start(self, string target, string user):
      self.work_process.Start(target, user)
  def Test(self, string target, string user, string reply):
      self.work_process.Test(target, user, reply)
  def GetReply(self):
      return self.work_process.GetReply()


# cdef extern from "greeter_client.cc":
#   void Job(string target, string user, string& reply)
