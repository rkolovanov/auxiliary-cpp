cmake_minimum_required(VERSION 3.21)
project(auxiliary-cpp
        VERSION 0.0.1
        DESCRIPTION "Библиотека вспомогательных решений C++"
        HOMEPAGE_URL "https://github.com/rkolovanov/auxiliary-cpp"
        LANGUAGES CXX)

option(WITH_TESTS "С тестами" ON)

set(CMAKE_CXX_STANDARD 23)
set(PROJECT_MODULES common gui)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Boost COMPONENTS date_time REQUIRED)
find_package(Qt5Core)
find_package(Qt5Widgets)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src)

foreach(MODULE ${PROJECT_MODULES})
    add_subdirectory(src/auxiliary/${MODULE})
endforeach()

if(WITH_TESTS)
    find_package(GTest)
    include_directories(${GTEST_INCLUDE_DIRS})
    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory(sandbox)