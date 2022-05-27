cmake_minimum_required(VERSION 3.22)
project(High_precision_real_number_library C)

set(CMAKE_C_STANDARD 99)

add_executable(High_precision_real_number_library main.c Utils Model GUI Public newCompute)
