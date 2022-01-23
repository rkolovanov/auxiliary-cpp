set(SOURCES src/AbstractStorage.cpp src/StorageCategory.cpp src/StorageContainer.cpp src/TimeUtils.cpp)
set(HEADERS AbstractStorage.h StorageCategory.h StorageContainer.h StorageContainerIndex.h TimeUtils.h)

add_library(auxiliary-cpp-common ${SOURCES} ${HEADERS})
target_link_libraries(auxiliary-cpp-common Qt5::Core Boost::date_time)

install(FILES ${HEADERS} DESTINATION ~/install COMPONENT devel)
