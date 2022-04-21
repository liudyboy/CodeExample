用 cython 将 asio 异步封装起来给 python 进行调用失败。编译会报如下错误:

/usr/include/boost/asio/impl/io_context.hpp:190:5: error: static assertion failed: CompletionHandler type requirements not met
  190 |     BOOST_ASIO_LEGACY_COMPLETION_HANDLER_CHECK(
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/boost/asio/impl/io_context.hpp:146:5: error: expression cannot be used as a function
  146 |     BOOST_ASIO_LEGACY_COMPLETION_HANDLER_CHECK(
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

