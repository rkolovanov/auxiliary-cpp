cmake_path(RELATIVE_PATH CMAKE_CURRENT_SOURCE_DIR
           BASE_DIRECTORY ${PROJECT_SOURCE_DIR}
           OUTPUT_VARIABLE RELATIVE_MODULE_PATH)

set(HEADERS
    MessageDialog.h
    QSfmlWidget.h)

set(SOURCES
    sources/MessageDialog.cpp
    sources/QSfmlWidget.cpp)

set(FORMS
    sources/MessageDialog.ui)

add_library(${MODULE_TARGET} SHARED ${HEADERS} ${SOURCES} ${FORMS})
set_target_properties(${MODULE_TARGET} PROPERTIES
                      OUTPUT_NAME ${MODULE_TARGET}
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${PROJECT_VERSION_MAJOR}
                      DEBUG_POSTFIX -debug)
target_link_libraries(${MODULE_TARGET} PRIVATE Qt6::Widgets)

install(TARGETS ${MODULE_TARGET}
        LIBRARY
        DESTINATION ${CBS_LIB_INSTALL_PATH}
        COMPONENT runtime)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
        PUBLIC_HEADER
        DESTINATION ${CBS_INCLUDE_INSTALL_PATH}/${RELATIVE_MODULE_PATH}
        COMPONENT dev
        FILES_MATCHING PATTERN "*.h"
        PATTERN "sources" EXCLUDE)
