#pragma once
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
#include <functional>

class mAsynchronousHandler {
 public:
  mAsynchronousHandler();
  template<class TASK>
    void Post(TASK task) {
    ios_.post(task);
  }
  void Run();
 private:
  boost::asio::io_service ios_;
};
