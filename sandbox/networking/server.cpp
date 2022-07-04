#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;

int main()
{
  int value = 0;
  io_service service;
  ip::tcp::endpoint listening_endpoint(ip::tcp::v4(), 9000);
  ip::tcp::acceptor acceptor(service, listening_endpoint);

  while(true)
  {
    ip::tcp::socket socket(service);
    acceptor.accept(socket);

    char data[256];
    socket.read_some(buffer(data, 256));
    std::cout << "Received data from '" << socket.remote_endpoint().address() << "': " << data << "\n";

    if(data[0] == 'o' && data[1] == 'k' && data[2] == '\0')
    {
      socket.write_some(buffer("Data: " + std::to_string(value)));
      ++value;
    }
    else if(data[0] == 'e' && data[1] == '\0')
    {
      socket.write_some(buffer("shutdown server"));
      break;
    }
    else
    {
      socket.write_some(buffer("unknown request"));
    }
  }

  return 0;
}