cmake_minimum_required(VERSION 3.5)

project(edit_distance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(edit_distance edit_distance.cpp)