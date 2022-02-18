# distutils: language = c++
# cython: language_level=3

from asy_handler cimport mAsynchronousHandler

cdef class PyAsy:
  cdef mAsynchronousHandler asy_handler
#  def __cinit__(self):
#      self.asy_handler = mAsynchronousHandler()
  def Post(self, task):
      self.asy_handler.Post(task)
  def Run(self):
      self.asy_handler.Run()
