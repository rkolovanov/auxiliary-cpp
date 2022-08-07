# Project header files
include_directories(${PROJECT_SOURCE_DIR})

# cmake-build-system
find_package(cmake-build-system 0.0.2 REQUIRED)

# Boost library
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.74.0 COMPONENTS chrono thread REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

# Qt 6 library
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.2.4 COMPONENTS Core Widgets REQUIRED)

include_directories(${Qt6Core_INCLUDE_DIRS})
include_directories(${Qt6Widgets_INCLUDE_DIRS})
