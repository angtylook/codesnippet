cmake_minimum_required(VERSION 3.16)

project(opencv)

set(CMAKE_TOOLCHAIN_FILE D:/devtools/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(VCPKG_TARGET_TRIPLET "x64-windows-static")

find_package(OpenCV REQUIRED)

add_executable(show_image show_image.cpp "video.cpp")
target_include_directories(show_image PRIVATE ${OpenCV_Include_Dirs})
target_link_libraries(show_image PRIVATE ${OpenCV_LIBS})
set_property(TARGET show_image PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_executable(video video.cpp "video.cpp")
target_include_directories(video PRIVATE ${OpenCV_Include_Dirs})
target_link_libraries(video PRIVATE ${OpenCV_LIBS})
set_property(TARGET video PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

