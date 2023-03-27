cmake_minimum_required(VERSION 3.24)
project(duLinkedList C)

set(CMAKE_C_STANDARD 99)

add_executable(duLinkedList main.c duLinkedList.h test.c)
