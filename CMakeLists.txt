cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(vec-span-demo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(compilerFlags "-D_CRT_SECURE_NO_WARNINGS /Zc:__cplusplus /permissive-\
        /w34100 /w34189 /w34701 /w34702 /w34703 /w34706 /w34714 /w34913\
        /wd4251 /wd4275"
    )
else()
    set(compilerFlags "-Wall -Wextra")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${compilerFlags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${compilerFlags}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./get_cpm.cmake)
CPMAddPackage(gh:iboB/itlib@1.5.1)
CPMAddPackage(gh:iboB/picobench@2.01)

macro(add_demo name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} itlib)
endmacro()

add_library(pb-main STATIC pb-main.cpp)
target_link_libraries(pb-main PUBLIC picobench)

macro(add_bench name)
    add_executable(${name}-bench ${name}-bench.cpp)
    target_link_libraries(${name}-bench itlib pb-main)
endmacro()

add_demo(moving)
add_demo(std-array)
add_demo(static_vector)
add_demo(small_vector)
add_demo(pod_vector)
add_demo(span)
add_demo(stride_span)
add_demo(poly_span)
add_demo(ranges)
add_bench(ranges)
