#include "greeter_client.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;


// Assembles the client's payload, sends it and presents the response back
// from the server.
std::string GreeterClient::SayHello(const std::string& user) {
  // Data we are sending to the server.
  HelloRequest request;
  request.set_name(user);

  // Container for the data we expect from the server.
  HelloReply reply;

  // Context for the client. It could be used to convey extra information to
  // the server and/or tweak certain RPC behaviors.
  ClientContext context;

  // The actual RPC.
  Status status = stub_->SayHello(&context, request, &reply);

  // Act upon its status.
  if (status.ok()) {
    return reply.message();
  } else {
    std::cout << status.error_code() << ": " << status.error_message()
              << std::endl;
    return "RPC failed";
  }
}

void GreeterClient::Connect(const std::string& target) {
  stub_ = Greeter::NewStub(CreateChannel(target, InsecureChannelCredentials()));
}


WorkProcess::~WorkProcess() {
  std::cout << "work process destroy called." << std::endl;
}

void WorkProcess::Test(const std::string& target, const std::string& user, std::string& reply) {

  std::string reply0;

  std::thread thread0(Job, target, user, std::ref(reply0));

  thread0.join();
  std::cout << "Test done. get reply: " << reply0 << std::endl;
}

void WorkProcess::Start(const std::string& target, const std::string& user) {
  thread_ = std::thread(Job, target, user, std::ref(reply_));
}

std::string WorkProcess::GetReply() {
  thread_.join();
  std::cout << "Thread job is done." << std::endl;
  return reply_;
}

void Job(std::string target, std::string user, std::string& reply) {
  GreeterClient client;
  client.Connect(target);
  reply = client.SayHello(user);
  std::cout << "In thread get reply: " << reply << std::endl;
}
