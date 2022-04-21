# distutils: language = c++
from libcpp.string cimport string

cdef extern from "Rectangle.cpp":
    pass
# 用cdef声明类
cdef extern from "Rectangle.h" namespace "shapes":
    cdef cppclass Rectangle:
        Rectangle() except +
        Rectangle(int, int, int, int) except +
        Rectangle(string msg) except +
        int x0, y0, x1, y1
        int getArea(string& msg)
        void getSize(int* width, int* height)
        void move(int, int)
