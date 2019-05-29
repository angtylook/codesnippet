cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#find_package(Boost REQUIRED date_time filesystem program_options)
#message(STATUS ${Boost_LIBRARIES})
#message(STATUS ${Boost_INCLUDE_DIRS})

set(SOURCE_FILES
        const.cpp
        deduct.cpp
        dolua.c
        expr.cpp
        item26.cpp
        let5.c
        move.cpp
        print.c
        print_thread_id.c
        random.cpp
        reg.cpp
        ret.cpp
        rvref.cpp
        std_async.cpp)

#target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES})
add_executable(constexpr const.cpp)
add_executable(reg reg.cpp)
add_executable(deduct deduct.cpp)
add_executable(delete delete.cpp)
add_executable(datetime datetime.cpp)
add_executable(item26 item26.cpp)
add_executable(move move.cpp)
add_executable(random random.cpp)
add_executable(async std_async.cpp)
add_executable(rvref rvref.cpp)
add_executable(expr expr.cpp)
add_executable(array array.cpp)
add_executable(regex11 regex11.cpp)

#target_include_directories(array PRIVATE ${Boost_INCLUDE_DIRS})
#target_link_libraries(array PRIVATE ${Boost_LIBRARIES})

