cmake_minimum_required(VERSION 3.7)
project(myList)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c defs.h list.c)
add_executable(myList ${SOURCE_FILES} defs.h list.c)