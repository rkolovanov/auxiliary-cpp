cmake_path(RELATIVE_PATH CMAKE_CURRENT_SOURCE_DIR
           BASE_DIRECTORY ${PROJECT_SOURCE_DIR}
           OUTPUT_VARIABLE RELATIVE_MODULE_PATH)

set(HEADERS
    Vector2D.h
    Vector3D.h)

set(SOURCES
    sources/Vector2D.cpp
    sources/Vector3D.cpp)

add_library(${MODULE_TARGET} SHARED ${HEADERS} ${SOURCES})
set_target_properties(${MODULE_TARGET} PROPERTIES
                      OUTPUT_NAME ${MODULE_TARGET}
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${PROJECT_VERSION_MAJOR}
                      DEBUG_POSTFIX -debug)
#target_link_libraries(${MATH_MODULE_TARGET} PRIVATE Qt6::Core Qt6::Widgets)

install(TARGETS ${MODULE_TARGET} LIBRARY DESTINATION ${CBS_LIB_INSTALL_PATH} COMPONENT runtime)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        PUBLIC_HEADER
        DESTINATION ${CBS_INCLUDE_INSTALL_PATH}/${RELATIVE_MODULE_PATH}
        COMPONENT dev
        FILES_MATCHING PATTERN "*.h"
        PATTERN "sources" EXCLUDE)