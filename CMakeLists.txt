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

find_package(Boost COMPONENTS chrono date_time thread REQUIRED)
find_package(Qt5Core)
find_package(Qt5Widgets)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/sources)

add_subdirectory(sandbox)

foreach(MODULE ${PROJECT_MODULES})
    add_subdirectory(sources/auxiliary/${MODULE})
endforeach()

if(WITH_TESTS)
    find_package(GTest)
    include_directories(${GTEST_INCLUDE_DIRS})
    enable_testing()
    add_subdirectory(tests)
endif()

# CPack

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_VENDOR "Rodion Kolovanov")
set(CPACK_PACKAGE_CONTACT "rodion.kolovanov@inbox.ru")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})

set(CPACK_VERBATIM_VARIABLES TRUE)
set(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_BINARY_DIR}/packages")
set(CPACK_PACKAGING_INSTALL_PREFIX "/opt/some")

set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
#set(CPACK_DEBIAN_PACKAGE_DEPENDS)

set(CPACK_DEBIAN_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})
set(CPACK_DEB_COMPONENT_INSTALL YES)

add_custom_target(pack-deb
        COMMAND cpack -G DEB
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        COMMENT "Pack .deb package"
        VERBATIM)

include(CPack)
