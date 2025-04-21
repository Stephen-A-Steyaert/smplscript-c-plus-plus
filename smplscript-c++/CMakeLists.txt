cmake_minimum_required(VERSION 3.31)

project(smplscript)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_subdirectory(src/library)
add_subdirectory(src/executable)
