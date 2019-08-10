cmake_minimum_required(VERSION 3.10)
project(thread)

find_package(Threads)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main main.cpp)
target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
add_executable(cv cv.cpp)
target_link_libraries(cv ${CMAKE_THREAD_LIBS_INIT})
