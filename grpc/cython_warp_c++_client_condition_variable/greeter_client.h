#pragma once
#include <memory>
#include <string>
#include <mutex>
#include <condition_variable>

#include <grpcpp/grpcpp.h>
#include <thread>
#include "helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;
using helloworld::Greeter;

class GreeterClient {
 public:

  GreeterClient() {}
  void Connect(const std::string& target);
  std::string SayHello(const std::string& user);

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};

class WorkProcess {
public:
  WorkProcess() {}
  ~WorkProcess();
  void Start(const std::string& target, const std::string& user);
  std::string GetReply();
  void Test(const std::string& target, const std::string& user, std::string& reply);
private:
  std::thread thread_;
  std::string reply_;
  std::mutex lock_;
  std::condition_variable cv_;
};

void Job(std::string target, std::string user,
         std::string& reply, std::condition_variable& cv);
