#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>

typedef std::function<void()> handler_t;
void foo(handler_t handler)
{
  std::cout << "Hello asio!" << std::endl;

  handler();
}

void handler_fun()
{
  std::cout << "mission complete!" << std::endl;
}

int main(int argc, char* argv[])
{
  boost::asio::io_context ios;
  auto work = boost::asio::require(ios.get_executor(), boost::asio::execution::outstanding_work.tracked);

  std::thread thread0([&ios]() {ios.run();});

  std::this_thread::sleep_for(std::chrono::seconds(1));

  ios.post(boost::bind(foo, handler_fun));

  std::cout << "second task" << std::endl;

  ios.post(boost::bind(foo, handler_fun));

  std::this_thread::sleep_for(std::chrono::seconds(1));
  ios.stop();
  thread0.join();
  return 0;
}
