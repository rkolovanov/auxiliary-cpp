set(SOURCES
        messages/sources/Message.cpp
        )

set(HEADERS
        messages/Message.h
        )

add_library(auxiliary-cpp-networking SHARED ${SOURCES} ${HEADERS})
target_link_libraries(auxiliary-cpp-networking pthread)

install(TARGETS auxiliary-cpp-networking LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR} COMPONENT dev)
