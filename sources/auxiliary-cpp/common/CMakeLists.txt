cmake_path(RELATIVE_PATH CMAKE_CURRENT_SOURCE_DIR
           BASE_DIRECTORY ${PROJECT_SOURCE_DIR}
           OUTPUT_VARIABLE RELATIVE_MODULE_PATH)

set(HEADERS
    Concepts.h
    Types.h)

add_custom_target(${MODULE_TARGET})
set_target_properties(${MODULE_TARGET} PROPERTIES
                      OUTPUT_NAME ${MODULE_TARGET}
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${PROJECT_VERSION_MAJOR}
                      DEBUG_POSTFIX -debug)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        PUBLIC_HEADER
        DESTINATION ${CBS_INCLUDE_INSTALL_PATH}/${RELATIVE_MODULE_PATH}
        COMPONENT dev
        FILES_MATCHING PATTERN "*.h"
        PATTERN "sources" EXCLUDE)
