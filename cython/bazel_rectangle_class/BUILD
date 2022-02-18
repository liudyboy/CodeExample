load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_python//python:defs.bzl", "py_library")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_proto_library", "cc_test")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@com_github_grpc_grpc//bazel:cython_library.bzl", "pyx_library")

cc_library(
  name = "c_rectangle",
  srcs = ["Rectangle.cpp",],
  hdrs = ["Rectangle.h", ],
  visibility = ["//visibility:public"],
)

py_runtime(
    name = "python3",
    interpreter_path = "/home/reas/miniconda3/bin/python",
)

pyx_library(
    name="rectangle_lib",
    srcs = glob([
        "*.pxd",
        "*.pyx",
        "Rectangle.cpp",
        "Rectangle.h",
    ]),
    deps = [
         ":c_rectangle",
    ],
    visibility=["//visibility:public"],
)

py_binary(
    name="test",
    srcs=["test.py"],
    main="test.py",
    srcs_version="PY3",
    visibility=["//visibility:public"],
    deps=["rectangle_lib"],
)