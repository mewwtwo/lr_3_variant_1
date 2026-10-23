cmake_minimum_required(VERSION 3.16)
project(lr_3_variant_1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(prog
    src/main.cpp
    src/schedule/schedule.cpp
    src/dependencies/dependencies.cpp
    src/action/action.cpp)
target_include_directories(prog PRIVATE src)
target_link_libraries(prog PRIVATE Threads::Threads)

if(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(prog PRIVATE -fexperimental-library)
    target_link_options(prog PRIVATE -fexperimental-library)
endif()

if(MINGW)
    target_link_options(prog PRIVATE -static)
endif()
