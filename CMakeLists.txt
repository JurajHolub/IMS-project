cmake_minimum_required(VERSION 3.14)
project(IMS_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMS_project main.cpp monthly_energy_flow.cpp monthly_energy_flow.h solar_energy_source.cpp solar_energy_source.h year_cycle.cpp year_cycle.h statistics.cpp statistics.h argument_parser.cpp argument_parser.h)
target_link_libraries(${PROJECT_NAME} m simlib)