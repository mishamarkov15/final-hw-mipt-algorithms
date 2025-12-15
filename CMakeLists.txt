cmake_minimum_required(VERSION 4.0)
project(final_hw)

set(CMAKE_CXX_STANDARD 23)

add_executable(final_hw main.cpp
        src/io/io.cpp
        src/utils/utils.cpp
)
