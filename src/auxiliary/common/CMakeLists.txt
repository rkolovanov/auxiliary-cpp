set(SOURCES storage/src/AbstractStorage.cpp
        storage/src/StorageCategory.cpp
        storage/src/StorageContainer.cpp
        src/TimeUtils.cpp)

set(HEADERS storage/AbstractStorage.h
        storage/StorageCategory.h
        storage/StorageContainer.h
        storage/StorageContainerIndex.h
        TimeUtils.h)

add_library(auxiliary-cpp-common ${SOURCES} ${HEADERS})
target_link_libraries(auxiliary-cpp-common Qt5::Core Boost::date_time)

install(FILES ${HEADERS} DESTINATION ~/install COMPONENT devel)
