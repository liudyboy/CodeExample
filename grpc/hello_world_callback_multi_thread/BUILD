package(default_visibility = ["//visibility:public"])
load("@com_github_grpc_grpc//bazel:grpc_build_system.bzl", "grpc_proto_library")

grpc_proto_library(
  name = "helloworld",
  srcs = ["helloworld.proto"],
)


cc_binary(
    name = "client",
    srcs = ["greeter_callback_client.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        ":helloworld",
    ],
  copts = [
    "-pthread",
  ],
)

cc_binary(
    name = "server",
    srcs = ["greeter_callback_server.cc"],
    defines = ["BAZEL_BUILD"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
        ":helloworld",
    ],
)
