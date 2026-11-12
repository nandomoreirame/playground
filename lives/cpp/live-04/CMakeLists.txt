cmake_minimum_required(VERSION 3.20)
project(live04 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(struct struct.cpp)
target_compile_options(struct PRIVATE -Wall -Wextra)
