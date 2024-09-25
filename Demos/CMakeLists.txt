cmake_minimum_required(VERSION 3.10)
project(Cpp_11_14_demos)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB ALL_HEADER_FILES 
    "*.h*")


add_executable(Cpp_11_14_demos main.cpp ${ALL_HEADER_FILES})
target_include_directories(Cpp_11_14_demos PUBLIC "*/")
#target_sources(Cpp_11_14_demos PRIVATE ${ALL_HEADER_FILES})

