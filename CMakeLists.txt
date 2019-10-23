cmake_minimum_required(VERSION 3.13)
project(labaratornaya1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(labaratornaya1 main.cpp matrix.h task_1.h test.h task_2.h)