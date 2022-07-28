cmake_minimum_required(VERSION 3.21)
project(auxiliary-cpp
        VERSION 0.0.1
        DESCRIPTION "Библиотека вспомогательных решений C++"
        HOMEPAGE_URL "https://github.com/rkolovanov/auxiliary-cpp"
        LANGUAGES CXX)

option(WITH_SANDBOX "С песочницей" OFF)
option(WITH_MANUAL_TESTS "С ручными тестами" OFF)
option(WITH_TESTS "С тестами" ON)

set(CMAKE_CXX_STANDARD 23)
set(PROJECT_MODULES common gui math networking)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Boost COMPONENTS chrono date_time thread REQUIRED)
find_package(Qt5Core)
find_package(Qt5Widgets)

include(GNUInstallDirs)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/sources)

foreach(MODULE ${PROJECT_MODULES})
    add_subdirectory(sources/${PROJECT_NAME}/${MODULE})
endforeach()

add_subdirectory(sandbox)
add_subdirectory(tests)

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
set(CPACK_PACKAGING_INSTALL_PREFIX "")

set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

set(CPACK_DEBIAN_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})
set(CPACK_DEB_COMPONENT_INSTALL ON)

add_custom_target(pack-deb
        COMMAND cpack -G DEB
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        COMMENT "Pack .deb package"
        VERBATIM)

include(CPack)
