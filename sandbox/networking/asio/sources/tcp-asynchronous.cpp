#include <iostream>
#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

using namespace boost;

void grabAllData(asio::ip::tcp::socket& socket, std::vector<char>& data)
{
  socket.async_receive(asio::buffer(data), {}, [&](const boost::system::error_code& error, size_t receivedBytes){
    if(!error)
    {
      for (int i = 0; i < receivedBytes; ++i)
      {
        std::cout << data[i];
      }

      grabAllData(socket, data);
    }
  });
}

int main()
{
  boost::system::error_code error;
  asio::io_context context;
  asio::io_context::work idleWork(context);
  boost::thread contextThread = boost::thread([&context](){ context.run(); });
  asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.216.34"), 80);
  asio::ip::tcp::socket socket(context);

  socket.connect(endpoint, error);

  if(!error && socket.is_open())
  {
    std::cout << "Connected!\n";
  }
  else
  {
    std::cout << "Failed to connect: " << error << "\n";
    return 0;
  }

  std::string requestData =
          "GET / HTTP/1.1\r\n"
          "Host: example.com\r\n"
          "Connection: close\r\n\r\n";
  socket.send(asio::buffer(requestData), {}, error);

  std::vector<char> data(1024);
  grabAllData(socket, data);

  boost::this_thread::sleep_for(boost::chrono::seconds(1));

  return 0;
}
