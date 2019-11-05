cmake_minimum_required(VERSION 3.14)
project(IMS_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMS_project main.cpp)
target_link_libraries(${PROJECT_NAME} m simlib)