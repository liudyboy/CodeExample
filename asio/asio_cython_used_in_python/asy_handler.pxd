cdef extern from "asy_handler.cpp":
  pass

cdef extern from "asy_handler.h":
  cdef cppclass mAsynchronousHandler:
    mAsynchronousHandler()
    void Post[TASK](TASK task)
    void Run()
