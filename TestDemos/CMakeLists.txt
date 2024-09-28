cmake_minimum_required(VERSION 3.10)
project(Cpp_11_14_demos)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB ALL_HEADER_FILES 
    "*.h*")
    in
#include_directories("../Include")


add_executable(Cpp_11_14_demos main.cpp ${ALL_HEADER_FILES})
target_include_directories(Cpp_11_14_demos PUBLIC 
"*/" 
"../include")
target_link_libraries(Cpp_11_14_demos PUBLIC AuxLibs)

#target_include_directories(App PRIVATE ../Include)
#target_sources(Cpp_11_14_demos PRIVATE ${ALL_HEADER_FILES})
#add_subdirectory("../Include")

