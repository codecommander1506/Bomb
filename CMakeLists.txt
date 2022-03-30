cmake_minimum_required(VERSION 3.20)

project(Bomb VERSION 1.0.0)

option(Bomb_BUILD_STATIC OFF)
option(Bomb_BUILD_TESTS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include(cmake/utils.cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(REQUIRED_QT_MODULES Core)
set(OPTIONAL_QT_MODULES Network)

if (Bomb_BUILD_TESTS)
    list(APPEND OPTIONAL_QT_MODULES Test)
endif()

find_package(Qt5 REQUIRED COMPONENTS ${REQUIRED_QT_MODULES} OPTIONAL_COMPONENTS ${OPTIONAL_QT_MODULES})

if (Bomb_BUILD_TESTS)
    if (NOT Qt5Test_FOUND)
        set(Bomb_BUILD_TESTS OFF)
        message(WARNING "QtTest not found, tests build skiped")
    else()
        find_package(GTest)

        if (NOT GTest_FOUND)
            set(Bomb_BUILD_TESTS OFF)
            message(WARNING "GTest not found, tests build skiped")
        endif()
    endif()
endif()

add_subdirectory(src)
if (Bomb_BUILD_TESTS)
    add_subdirectory(tests)
endif()
