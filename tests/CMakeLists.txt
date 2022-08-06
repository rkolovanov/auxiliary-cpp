if(WITH_TESTS)
  find_package(GTest)
  include_directories(${GTEST_INCLUDE_DIRS})
  enable_testing()

  add_subdirectory(auto)

  if(WITH_MANUAL_TESTS)
    add_subdirectory(manual)
  endif()
endif()
