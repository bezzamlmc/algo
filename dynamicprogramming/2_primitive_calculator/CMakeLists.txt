cmake_minimum_required(VERSION 3.5)

project(primitive_calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(primitive_calculator primitive_calculator.cpp)