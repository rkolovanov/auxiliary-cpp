add_executable(sandbox-networking-client networking/client.cpp)
add_executable(sandbox-networking-server networking/server.cpp)

target_link_libraries(sandbox-networking-client pthread)
target_link_libraries(sandbox-networking-server pthread)