add_executable(MessageDialog_ManualTest MessageDialog_ManualTest.cpp)
target_link_libraries(MessageDialog_ManualTest auxiliary-cpp-gui Qt5::Core Qt5::Widgets)

add_executable(QSfmlWidget_ManualTest QSfmlWidget_ManualTest.cpp)
target_link_libraries(QSfmlWidget_ManualTest auxiliary-cpp-gui Qt5::Core Qt5::Widgets sfml-graphics)

