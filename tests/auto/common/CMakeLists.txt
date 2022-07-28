add_executable(StorageCategory_Test StorageCategory_Test.cpp)
target_link_libraries(StorageCategory_Test auxiliary-cpp-common GTest::GTest)

add_executable(StorageContainer_Test StorageContainer_Test.cpp)
target_link_libraries(StorageContainer_Test auxiliary-cpp-common GTest::GTest)
