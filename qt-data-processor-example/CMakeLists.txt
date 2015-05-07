cmake_minimum_required (VERSION 2.6)
project (external-data-processor-example)
include(local.cmake)


FIND_PACKAGE(Qt4 REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(QXT_USE_QXTCORE TRUE)
SET(QXT_USE_QXTWEB TRUE)
SET(QT_DONT_USE_QTGUI TRUE)
SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTXML TRUE)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

INCLUDE(${QT_USE_FILE})

enable_testing()

add_subdirectory (src)

if (DISABLE_COMPILE_TESTS)
	message("-- Skipping compile tests")
else()
    add_subdirectory (test) 
endif()
