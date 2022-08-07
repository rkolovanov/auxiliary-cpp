if(WITH_SANDBOX)
  add_subdirectory(networking)

  add_executable(sandbox-temp temp.cpp)
  target_link_libraries(sandbox-temp pthread)
endif()
