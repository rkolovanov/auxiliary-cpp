cmake_minimum_required(VERSION 3.22)
project(auxiliary-cpp
        VERSION 0.0.2
        DESCRIPTION "Библиотека вспомогательных компонентов C++"
        HOMEPAGE_URL "https://github.com/rkolovanov/auxiliary-cpp"
        LANGUAGES CXX)

option(WITH_SANDBOX "С песочницей" OFF)
option(WITH_MANUAL_TESTS "С ручными тестами" OFF)
option(WITH_TESTS "С тестами" ON)

set(CMAKE_CXX_STANDARD 23)
set(PROJECT_MODULES common gui math networking)

include(cmake/Libraries.cmake)
include(GNUInstallDirs)

include_directories(${CMAKE_SOURCE_DIR}/sources)

foreach(MODULE ${PROJECT_MODULES})
    add_subdirectory(sources/${PROJECT_NAME}/${MODULE})
endforeach()

add_subdirectory(sandbox)
add_subdirectory(tests)

include(cmake/Pack.cmake)
