set(SOURCES sources/MessageDialog.cpp)

set(HEADERS MessageDialog.h)

set(FORMS sources/MessageDialog.ui)

add_library(auxiliary-cpp-gui SHARED ${SOURCES} ${HEADERS} ${FORMS})
target_link_libraries(auxiliary-cpp-gui Qt5::Core Qt5::Widgets)

install(TARGETS auxiliary-cpp-gui LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR} COMPONENT dev)
