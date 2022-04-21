load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_python//python:defs.bzl", "py_library")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_proto_library", "cc_test")
load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@com_github_grpc_grpc//bazel:cython_library.bzl", "pyx_library")
load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

grpc_proto_library(
  name = "hello_grpc",
  srcs = ["helloworld.proto"],
)

cc_library(
  name = "client",
  srcs = [
    "greeter_client.cc",
  ],
  hdrs = [
    "greeter_client.h",
  ],
  deps = [
    ":hello_grpc",
    "@com_github_grpc_grpc//:grpc++",
    "@com_github_grpc_grpc//:grpc++_reflection",
  ],
)

pyx_library(
  name = "PyClient_lib",
  srcs = glob([
       "*.pxd",
       "*pyx",
  ]),
  deps = [
     ":client",
  ],
)

cc_binary(
  name = "server",
  srcs = ["greeter_server.cc"],
  deps = [
    ":hello_grpc",
    "@com_github_grpc_grpc//:grpc++",
    "@com_github_grpc_grpc//:grpc++_reflection",
  ],
)

py_binary(
  name = "py_client",
  srcs = ["py_client.py"],
  main = "py_client.py",
  srcs_version = "PY3",
  visibility=["//visibility:public"],
  deps=["PyClient_lib"],
)
