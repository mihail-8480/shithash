cmake_minimum_required(VERSION 3.24)
project(shithash)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wpedantic -Wall")

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    message("-- Building in debug mode")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -O0 -ggdb3 -fsized-deallocation")
else()
    message("-- Building in release mode")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Ofast -fsized-deallocation")
endif()

add_executable(shithash-8 main.cpp)
target_compile_definitions(shithash-8 PRIVATE BITS=8)

add_executable(shithash-16 main.cpp)
target_compile_definitions(shithash-16 PRIVATE BITS=16)

add_executable(shithash-32 main.cpp)
target_compile_definitions(shithash-32 PRIVATE BITS=32)

add_executable(shithash-64 main.cpp)
target_compile_definitions(shithash-64 PRIVATE BITS=64)

add_executable(shithash-128 main.cpp)
target_compile_definitions(shithash-128 PRIVATE BITS=128)

add_executable(shithash-256 main.cpp)
target_compile_definitions(shithash-256 PRIVATE BITS=256)

add_executable(shithash-384 main.cpp)
target_compile_definitions(shithash-384 PRIVATE BITS=384)

add_executable(shithash-512 main.cpp)
target_compile_definitions(shithash-512 PRIVATE BITS=512)

add_executable(shithash-1024 main.cpp)
target_compile_definitions(shithash-1024 PRIVATE BITS=1024)

add_executable(shithash-2048 main.cpp)
target_compile_definitions(shithash-2048 PRIVATE BITS=2048)

add_executable(shithash-4096 main.cpp)
target_compile_definitions(shithash-2048 PRIVATE BITS=4096)

add_executable(shithash-8192 main.cpp)
target_compile_definitions(shithash-8192 PRIVATE BITS=8192)

add_executable(shithash-16384 main.cpp)
target_compile_definitions(shithash-16384 PRIVATE BITS=16384)

add_executable(shithash-32768 main.cpp)
target_compile_definitions(shithash-32768 PRIVATE BITS=32768)

add_executable(shithash-65536 main.cpp)
target_compile_definitions(shithash-65536 PRIVATE BITS=65536)