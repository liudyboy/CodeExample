## run
```
bazel run //:test
```

## Issues

May be occur error:

```
bazel-out/k8-fastbuild/bin/PyRectangle.cpp:628:10: fatal error: Rectangle.cpp: No such file or directory
 #include "Rectangle.cpp"
          ^~~~~~~~~~~~~~~
compilation terminated.
```

To resolve the problem, we need to set the `CPLUS_INCLUDE_PATH` to include the path that includes `Rectangle.cpp` file.