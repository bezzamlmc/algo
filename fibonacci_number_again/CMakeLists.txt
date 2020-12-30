cmake_minimum_required(VERSION 3.5)

project(fibonacci_huge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fibonacci_huge fibonacci_huge.cpp)
