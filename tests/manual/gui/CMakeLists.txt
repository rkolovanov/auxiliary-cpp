add_executable(MessageDialog_ManualTest MessageDialog_ManualTest.cpp)
target_link_libraries(MessageDialog_ManualTest auxiliary-cpp-gui Qt6::Core Qt6::Widgets)

add_executable(QSfmlWidget_ManualTest QSfmlWidget_ManualTest.cpp)
target_link_libraries(QSfmlWidget_ManualTest auxiliary-cpp-gui Qt6::Core Qt6::Widgets sfml-graphics)

