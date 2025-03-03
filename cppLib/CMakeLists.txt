cmake_minimum_required(VERSION 3.20)

project(demoTaskLib)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/cppLib)

set(SOURCES
    custom_parser_jni.cpp
    custom_parser.cpp
)

add_library(demoTaskLib
    SHARED
    ${SOURCES}
)

target_link_libraries(demoTaskLib
    ${JNI_LIBRARIES}
)