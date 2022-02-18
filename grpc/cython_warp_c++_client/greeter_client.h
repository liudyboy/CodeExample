/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


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

  GreeterClient(std::string target_str) {}
  GreeterClient(std::string target_str)
      : stub_(Greeter::NewStub(CreateChannel(target_str,
             InsecureChannelCredentials()))) {
      }

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SayHello(const std::string& user);

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};
