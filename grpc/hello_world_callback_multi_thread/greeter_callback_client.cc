/*
 *
 * Copyright 2021 gRPC authors.
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

#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <time.h>
#include <grpcpp/grpcpp.h>

#include "helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

  std::string SayHello(const std::string& user) {
    std::string target_str = "localhost:50051";
    std::unique_ptr<Greeter::Stub> stub = Greeter::NewStub(grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
    // Data we are sending to the server.
    HelloRequest request;
    request.set_name(user);

    // Container for the data we expect from the server.
    HelloReply reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    std::mutex mu;
    std::condition_variable cv;
    bool done = false;
    Status status;
    stub->async()->SayHello(&context, &request, &reply,
                             [&mu, &cv, &done, &status](Status s) {
                               status = std::move(s);
                               std::lock_guard<std::mutex> lock(mu);
                               done = true;
                               cv.notify_one();
                             });

    std::unique_lock<std::mutex> lock(mu);
    while (!done) {
      cv.wait(lock);
    }

    // Act upon its status.
    if (status.ok()) {
      std::cout << "reply: " << reply.message() << std::endl;
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

using std::chrono::system_clock;
int main(int argc, char** argv) {
  system_clock::time_point start = system_clock::now();
  std::string user("worker0");
  std::thread worker0(SayHello, user);

  // user = "worker1";
  // std::thread worker1(SayHello, user);
  // worker1.join();

  worker0.join();

  system_clock::time_point end = system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "time = " << elapsed_seconds.count() << "s" << std::endl;
  return 0;
}
