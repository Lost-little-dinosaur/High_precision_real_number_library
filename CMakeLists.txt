cmake_minimum_required(VERSION 3.22)
project(High_precision_real_number_library C)

file(GLOB SOURCES
        *.h //*号对应具体的文件名
        *.c
        )
set(CMAKE_C_STANDARD 99)

MATH(EXPR stack_size "64*1024*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

file(GLOB SRC_LIST1 "newCompute/*.c")
file(GLOB SRC_PROTOCOL_LIST1 "newCompute/*.h")
file(GLOB SRC_LIST2 "Utils/*.c")
file(GLOB SRC_PROTOCOL_LIST2 "Utils/*.h")
add_library(demo ${SRC_LIST1} ${SRC_PROTOCOL_LIST1} ${SRC_LIST2} ${SRC_PROTOCOL_LIST2} GUI/gui.c newCompute/misc.c newCompute/misc.h)

add_executable(High_precision_real_number_library main.c Utils Model GUI Public newCompute  ${SRC_LIST1} ${SRC_PROTOCOL_LIST1} ${SRC_LIST2} ${SRC_PROTOCOL_LIST2} GUI/gui.c)
