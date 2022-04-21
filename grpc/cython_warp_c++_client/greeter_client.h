#pragma once
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/helloworld.grpc.pb.h"
#else
#include "helloworld.grpc.pb.h"
#endif

using grpc::Channel;
using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;
// using grpc::ClientContext;
// using grpc::Status;
using helloworld::Greeter;
// using helloworld::HelloReply;
// using helloworld::HelloRequest;

class GreeterClient {
 public:

  GreeterClient() {}
  // GreeterClient(std::string target_str)
  //     : stub_(Greeter::NewStub(CreateChannel(target_str,
  //            InsecureChannelCredentials()))) {
  //     }
  void Connect(std::string target);
  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const std::string& user);

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};
