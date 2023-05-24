cmake_minimum_required(VERSION 3.25)
project(Grade-management-system C)

set(CMAKE_C_STANDARD 11)

MATH(EXPR stack_size "5*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

file(GLOB SOURCES "Src/*.c")
file(GLOB HEADERS "Inc/*.h")

add_executable(Grade-management-system ${SOURCES} ${HEADERS} Src/exportData.c Inc/exportData.h Src/sort.c Inc/sort.h)
