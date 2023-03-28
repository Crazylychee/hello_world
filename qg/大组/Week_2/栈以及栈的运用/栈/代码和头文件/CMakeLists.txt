cmake_minimum_required(VERSION 3.24)
project(Stack C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack Linkstack/main.c Linkstack/LinkStack.h Linkstack/LinkStack.c)
