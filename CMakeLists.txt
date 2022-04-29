cmake_minimum_required(VERSION 3.17)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads)

#add_executable(cpp_practice  key_point/thread/threadCreate2.cpp)
add_executable(cpp_practice  key_point/thread/callonce.cpp)
add_executable(cpp_practice2  key_point/vector/emplace.cpp)

target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})