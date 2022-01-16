set(SOURCES src/TimeUtils.cpp)
set(HEADERS TimeUtils.h)

add_library(auxiliary-cpp-common ${SOURCES} ${HEADERS})
target_link_libraries(auxiliary-cpp-common Qt5::Core Boost::date_time)

install(FILES ${HEADERS} DESTINATION ~/install COMPONENT devel)
