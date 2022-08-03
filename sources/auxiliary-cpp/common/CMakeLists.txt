set(SOURCES
        storage/sources/AbstractStorage.cpp
        storage/sources/StorageCategory.cpp
        storage/sources/StorageContainer.cpp
        )

set(HEADERS
        storage/AbstractStorage.h
        storage/StorageCategory.h
        storage/StorageContainer.h
        storage/StorageContainerIndex.h
        Concepts.h
        )

add_library(auxiliary-cpp-common SHARED ${SOURCES} ${HEADERS})
target_link_libraries(auxiliary-cpp-common Qt6::Core Boost::date_time)

install(TARGETS auxiliary-cpp-common LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR} COMPONENT dev)
