set(SOURCES storage/sources/AbstractStorage.cpp
        storage/sources/StorageCategory.cpp
        storage/sources/StorageContainer.cpp
        sources/TimeUtils.cpp
        sources/Vector.cpp)

set(HEADERS storage/AbstractStorage.h
        storage/StorageCategory.h
        storage/StorageContainer.h
        storage/StorageContainerIndex.h
        TimeUtils.h
        Vector.h)

add_library(auxiliary-cpp-common SHARED ${SOURCES} ${HEADERS})
target_link_libraries(auxiliary-cpp-common Qt5::Core Boost::date_time)

install(FILES ${})
install(FILES ${HEADERS} DESTINATION ~/install COMPONENT dev)
