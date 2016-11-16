cmake_minimum_required(VERSION 3.6)
project(hackerrank_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(READ classes/boxit/list.properties SOURCE_FILES_classes_boxit)
STRING(REGEX REPLACE "\n" ";" SOURCE_FILES_classes_boxit "${SOURCE_FILES_classes_boxit}")
add_executable(hackerrank_cpp_classes_boxit ${SOURCE_FILES_classes_boxit})

set(SOURCE_FILES main.cpp)
add_executable(hackerrank_cpp ${SOURCE_FILES})
