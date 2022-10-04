add_executable(Vector2D_Test Vector2D_Test.cpp)
target_link_libraries(Vector2D_Test gtest auxiliary-cpp-math)
add_test(NAME Vector2D_Test COMMAND Vector2D_Test)

add_executable(Vector3D_Test Vector3D_Test.cpp)
target_link_libraries(Vector3D_Test gtest auxiliary-cpp-math)
add_test(NAME Vector3D_Test COMMAND Vector3D_Test)

add_executable(Vector4D_Test Vector4D_Test.cpp)
target_link_libraries(Vector4D_Test gtest auxiliary-cpp-math)
add_test(NAME Vector4D_Test COMMAND Vector4D_Test)
