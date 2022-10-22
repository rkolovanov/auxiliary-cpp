# Add package information
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_DEBIAN_BUILDREQUIRES "cmake >= 3.16, libboost-all-dev >= 1.74.0, qt6-base-dev >= 6.2.4") # TODO: Add
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libboost-all-dev (>= 1.74.0), qt6-base-dev (>= 6.2.4)") # TODO: Add

# Include cmake-build-system Pack.cmake
if(DEFINED CMAKE_BUILD_SYSTEM_DIR)
  include(${CMAKE_BUILD_SYSTEM_DIR}/Pack.cmake)
endif()

# Dependencies for cmake-build-system pack targets
add_dependencies(pack-deb ${PROJECT_NAME})
add_dependencies(pack-rpm ${PROJECT_NAME})

# Library Cmake configuration file
include(CMakePackageConfigHelpers)

configure_package_config_file(templates/${PROJECT_NAME}-config.cmake.in
                              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
                              INSTALL_DESTINATION ${CBS_CMAKE_CONFIG_FILES_PATH})
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION ${CBS_CMAKE_CONFIG_FILES_PATH}
        COMPONENT dev)
