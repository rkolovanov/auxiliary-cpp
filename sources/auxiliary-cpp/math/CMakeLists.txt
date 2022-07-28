set(SOURCES
        )

set(HEADERS
        geometry/Vector.h
        )

add_library(auxiliary-cpp-math SHARED ${SOURCES} ${HEADERS})
target_link_libraries(auxiliary-cpp-math pthread)

install(TARGETS auxiliary-cpp-math LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR} COMPONENT dev)
