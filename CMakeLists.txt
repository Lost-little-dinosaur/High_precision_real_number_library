cmake_minimum_required(VERSION 3.22)
project(High_precision_real_number_library C)

file(GLOB SOURCES
        *.h //*号对应具体的文件名
        *.c
        )
set(CMAKE_C_STANDARD 99)

file(GLOB SRC_LIST "newCompute/*.c")
file(GLOB SRC_PROTOCOL_LIST "newCompute/*.h")
add_library(demo ${SRC_LIST} ${SRC_PROTOCOL_LIST})

add_executable(High_precision_real_number_library main.c Utils Model GUI Public newCompute  ${SRC_LIST} ${SRC_PROTOCOL_LIST})
