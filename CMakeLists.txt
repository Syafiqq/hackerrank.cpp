cmake_minimum_required(VERSION 3.6)
project(hackerrank_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#introduction
#virtual function
file(READ introduction/virtual_function/list.properties SOURCE_FILES_introduction_virtual_function)
STRING(REGEX REPLACE "\n" ";" SOURCE_FILES_introduction_virtual_function "${SOURCE_FILES_introduction_virtual_function}")
add_executable(hackerrank_cpp_introduction_virtual_function ${SOURCE_FILES_introduction_virtual_function})

#classes
#boxit
file(READ classes/boxit/list.properties SOURCE_FILES_classes_boxit)
STRING(REGEX REPLACE "\n" ";" SOURCE_FILES_classes_boxit "${SOURCE_FILES_classes_boxit}")
add_executable(hackerrank_cpp_classes_boxit ${SOURCE_FILES_classes_boxit})

#other concepts
#attending workshops
file(READ other_concepts/attending_workshops/list.properties SOURCE_FILES_other_concepts_attending_workshops)
STRING(REGEX REPLACE "\n" ";" SOURCE_FILES_other_concepts_attending_workshops "${SOURCE_FILES_other_concepts_attending_workshops}")
add_executable(hackerrank_cpp_other_concepts_attending_workshops ${SOURCE_FILES_other_concepts_attending_workshops})

set(SOURCE_FILES main.cpp)
add_executable(hackerrank_cpp ${SOURCE_FILES})
