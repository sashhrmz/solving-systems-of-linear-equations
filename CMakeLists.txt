cmake_minimum_required(VERSION 3.13)
project(labaratornaya1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

add_executable(labaratornaya1 main.cpp task_1.h matrix.cpp matrix.h test.h task_2.h)