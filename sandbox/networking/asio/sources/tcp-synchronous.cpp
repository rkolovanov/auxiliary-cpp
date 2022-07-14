#include <iostream>
#include <boost/asio.hpp>

using namespace boost;

int main()
{
  boost::system::error_code error;
  asio::io_context context;
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

  socket.wait(socket.wait_read);

  size_t bytesAvailable = socket.available();
  std::cout << "Bytes available: " << bytesAvailable << "\n";

  if(bytesAvailable > 0)
  {
    std::vector<char> receivedData(bytesAvailable);
    socket.receive(asio::buffer(receivedData), {}, error);

    for(const auto& c : receivedData)
    {
      std::cout << c;
    }
  }

  return 0;
}
