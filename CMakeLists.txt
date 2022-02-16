cmake_minimum_required(VERSION 3.17)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_practice main.cpp key_point/memory_model/todo.cpp gcc/hello.c gcc/test.c static_lib/calc/head.h static_lib/calc/add.c static_lib/calc/sub.c static_lib/calc/mult.c static_lib/calc/div.c static_lib/calc/main.c)