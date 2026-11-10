cmake_minimum_required(VERSION 3.20)
project(live01 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(secret_number secret_number.cpp)
target_compile_options(secret_number PRIVATE -Wall -Wextra)
