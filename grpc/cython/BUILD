cc_library(
  name = "scheduler",
  srcs = glob([
    "scheduler/*.cpp",
  ]),
  hdrs = glob([
    "scheduler/*.hpp",
  ]),
  deps = [
    "@com_github_google_glog//:glog",
    "//grpc:task_grpc",
    "@com_github_grpc_grpc//:grpc++",
    "@com_github_grpc_grpc//:grpc++_reflection",
  ],
)

pyx_library(
  name = "PyClient",
  srcs = glob([
       "*.pyx"
  ]),
  deps = [
    "@com_github_grpc_grpc//:grpc++",
    "@com_github_grpc_grpc//:grpc++_reflection",
    ]
)