# Project header files
include_directories(${PROJECT_SOURCE_DIR})

# Libraries configuration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

# Find libraries
find_package(cmake-build-system 0.0.2 REQUIRED)
find_package(Boost 1.74.0 COMPONENTS chrono thread REQUIRED)
find_package(Qt6 6.2.4 COMPONENTS Core Widgets REQUIRED)
find_package(SFML 2.5.1 COMPONENTS system graphics window REQUIRED)

if(WITH_TESTS)
  find_package(GTest 1.11.0 REQUIRED)
endif()
