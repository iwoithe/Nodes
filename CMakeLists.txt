cmake_minimum_required(VERSION 3.21)
project(nodes)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

option(QT_SUPPORT "Build with Qt support" OFF)
if (QT_SUPPORT)
    set(QT_COMPONENTS
        Core
        Gui
    )

    set(QT_LIBRARIES
        Qt5::Core
        Qt5::Gui
    )

    find_package(Qt5 COMPONENTS ${QT_COMPONENTS} REQUIRED)
endif (QT_SUPPORT)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_BINARY_DIR}/generated/config.h)
include_directories(${CMAKE_BINARY_DIR}/generated)

add_subdirectory(src)
