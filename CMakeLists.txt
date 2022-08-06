cmake_minimum_required(VERSION 3.22)
project(auxiliary-cpp
        VERSION 0.0.2
        DESCRIPTION "Библиотека вспомогательных компонентов C++"
        HOMEPAGE_URL "https://github.com/rkolovanov/auxiliary-cpp"
        LANGUAGES CXX)

option(WITH_SANDBOX "С песочницей" OFF)
option(WITH_MANUAL_TESTS "С ручными тестами" ON)
option(WITH_TESTS "С тестами" ON)

set(CMAKE_CXX_STANDARD 23)
set(PROJECT_MODULES common gui math networking)

include(cmake/Libraries.cmake)

include_directories(${CMAKE_SOURCE_DIR}/sources)

add_custom_target(${PROJECT_NAME})

foreach(MODULE_NAME ${PROJECT_MODULES})
  set(MODULE_TARGET ${PROJECT_NAME}-${MODULE_NAME})
  add_subdirectory(sources/${PROJECT_NAME}/${MODULE_NAME})
  add_dependencies(${PROJECT_NAME} ${MODULE_TARGET})
endforeach()

add_subdirectory(sandbox)
add_subdirectory(tests)

add_dependencies(pack-deb ${PROJECT_NAME})
add_dependencies(pack-rpm ${PROJECT_NAME})
