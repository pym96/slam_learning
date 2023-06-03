cmake_minimum_required(VERSION 3.0)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(test_src test)
add_library(auto_aim OBJECT auto_aim.cpp ${test})