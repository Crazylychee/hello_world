cmake_minimum_required(VERSION 3.24)
project(Queue C)

set(CMAKE_C_STANDARD 99)

add_executable(Queue main.c QG_queue_main.c LQueue.c)
