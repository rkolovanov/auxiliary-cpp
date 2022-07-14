add_executable(sandbox-networking-client sources/client.cpp)
add_executable(sandbox-networking-server sources/server.cpp)

target_link_libraries(sandbox-networking-client pthread)
target_link_libraries(sandbox-networking-server pthread)
