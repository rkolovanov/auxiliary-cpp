#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;

int main()
{
  io_service service;
  ip::tcp::endpoint endpoint(ip::address::from_string("127.0.0.1"), 9000);
  ip::tcp::socket socket(service);

  socket.open(ip::tcp::v4());
  socket.connect(endpoint);

  std::string input;
  std::cin >> input;
  socket.write_some(buffer(input.data(), input.size() + 1));

  char data[256];
  socket.receive(buffer(data, 256));
  std::cout << "Received data from server: " << data << "\n";

  return 0;
}