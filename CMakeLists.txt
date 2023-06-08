cmake_minimum_required(VERSION 3.0)
project(MA)

## Use c++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g  -pthread -Wl,--no-as-needed" )

## By adding -Wall and -Werror, the complier does not ignore warnings
## enforcing cleaner code
add_definitions(-Wall -Werror)
add_compile_options(-Wall -Werror=return-type -Wno-unused-variable)


## Export compile commands for clangd
set(CAMKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} run_and_compile.cpp)
add_executable(PRAC eigen_practice.cpp)

## Find package
find_package(Eigen3 REQUIRED)
find_package(fmt REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

## Link library
include_directories(auto_aim)
add_subdirectory(include)
target_link_libraries(MA 
        auto_aim 
        fmt::fmt)

