add_executable(networking-asio-tcp-synchronous sources/tcp-synchronous.cpp)
add_executable(networking-asio-tcp-asynchronous sources/tcp-asynchronous.cpp)

target_link_libraries(networking-asio-tcp-synchronous pthread)
target_link_libraries(networking-asio-tcp-asynchronous Boost::chrono Boost::thread pthread)
