cmake_minimum_required(VERSION 3.20)
project(light_logger)

set(CMAKE_CXX_STANDARD 17)

add_executable(light_logger main.cpp logger.cpp logger.h)
target_link_libraries(light_logger pthread)