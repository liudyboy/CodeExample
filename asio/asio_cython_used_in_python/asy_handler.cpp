#include "asy_handler.h"

mAsynchronousHandler::mAsynchronousHandler() {}

void mAsynchronousHandler::Run() { ios_.run(); }

// typedef std::function<void()> handler_t;

// void foo(handler_t handler)
// {
//   std::cout << "Hello asio!" << std::endl;

//   handler();
// }

// void handler_fun()
// {
//   std::cout << "mission complete!" << std::endl;
// }


// int main() {
//   AsynchronousHandler asy_handler;
//   asy_handler.Post(boost::bind(foo, handler_fun));
//   std::cout << "Start to run " << std::endl;
//   asy_handler.Run();
//   return 0;
// }
