cmake_minimum_required(VERSION 3.24)
project(队列 C)

set(CMAKE_CXX_STANDARD 14)

include_directories(代码和头文件/LQueue)

add_executable(
        代码和头文件/LQueue/LQueue.c
        代码和头文件/LQueue/LQueue.h
        代码和头文件/LQueue/QG_queue_main.cpp)
