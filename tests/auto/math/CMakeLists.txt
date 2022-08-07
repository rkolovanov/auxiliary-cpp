add_executable(Vector3D_Test Vector3D_Test.cpp)
target_link_libraries(Vector3D_Test gtest auxiliary-cpp-math)
add_test(NAME Vector3D_Test COMMAND Vector3D_Test)
