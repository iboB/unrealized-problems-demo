cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(unrealized-problems-demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(compilerFlags "-D_CRT_SECURE_NO_WARNINGS /wd4251 /wd4275 /w34100 /Zc:__cplusplus /permissive-")
else()
    set(compilerFlags "-Wall -Wextra")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${compilerFlags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${compilerFlags}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CPM.cmake and packages
include(./get_cpm.cmake)
CPMAddPackage(gh:iboB/itlib@1.4.5)

# Demos
macro(add_demo name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} itlib)
endmacro()

add_demo(00-copy-over-move)
add_demo(01-func-move-noexcept-false)
add_demo(02-capture-non-copy)

