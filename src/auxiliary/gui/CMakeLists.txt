set(SOURCES src/MessageDialog.cpp)

set(HEADERS MessageDialog.h)

set(FORMS src/MessageDialog.ui)

add_library(auxiliary-cpp-gui SHARED ${SOURCES} ${HEADERS} ${FORMS})
target_link_libraries(auxiliary-cpp-gui Qt5::Core Qt5::Widgets)

install(FILES ${HEADERS} DESTINATION ~/install COMPONENT devel)
