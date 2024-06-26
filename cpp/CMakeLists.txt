cmake_minimum_required(VERSION 3.20)
project(cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#find_package(Boost REQUIRED date_time filesystem program_options)
#message(STATUS ${Boost_LIBRARIES})
#message(STATUS ${Boost_INCLUDE_DIRS})

#find_package(nlohmann_json CONFIG REQUIRED)

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
add_executable(for for.cpp)
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
add_executable(range_demo range_demo.cpp)
#add_executable(views views.cpp)
#add_executable(json json.cpp)
add_executable(trim_email trim_email.cpp)
add_executable(iterator iterator.cpp)
add_executable(unique unique.cpp)
add_executable(cxx23 cxx23.cpp)
add_executable(ret ret.cpp)
add_executable(cxx_jthread cxx_jthread.cpp)
add_executable(queue queue.cpp bounded_channel.h)
add_executable(cycle_thread cycle_thread.h cycle_thread.cpp cycle_main.cpp)
add_executable(normal normal.cpp)

#target_link_libraries(json PRIVATE nlohmann_json nlohmann_json::nlohmann_json)

#target_include_directories(array PRIVATE ${Boost_INCLUDE_DIRS})
#target_link_libraries(array PRIVATE ${Boost_LIBRARIES})
#[[
add_executable(boost_main boost.cpp)
target_include_directories(boost_main PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(boost_main PRIVATE ${Boost_LIBRARIES})

find_package(libuv)

add_executable(uv_timer uv_timer.cpp)
target_link_libraries(uv_timer PRIVATE $<IF:$<TARGET_EXISTS:uv_a>,uv_a,uv>)

add_executable(uv_work uv_work.cpp)
target_link_libraries(uv_work PRIVATE $<IF:$<TARGET_EXISTS:uv_a>,uv_a,uv>)

add_executable(uv_loop uv_loop.cpp)
target_link_libraries(uv_loop PRIVATE $<IF:$<TARGET_EXISTS:uv_a>,uv_a,uv>)

add_executable(uv_fs uv_fs.cpp)
target_link_libraries(uv_fs PRIVATE unofficial::libuv::libuv)
]]
