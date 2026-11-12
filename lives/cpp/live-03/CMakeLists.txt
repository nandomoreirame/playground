cmake_minimum_required(VERSION 3.20)
project(live03 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(03-estatisticas live-03-estatisticas.cpp)
target_compile_options(03-estatisticas PRIVATE -Wall -Wextra)
