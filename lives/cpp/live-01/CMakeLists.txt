cmake_minimum_required(VERSION 3.20)
project(live01 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello hello.cpp)
target_compile_options(hello PRIVATE -Wall -Wextra)

add_executable(ops ops.cpp)
target_compile_options(ops PRIVATE -Wall -Wextra)

add_executable(final final.cpp)
target_compile_options(final PRIVATE -Wall -Wextra)
