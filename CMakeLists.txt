cmake_minimum_required(VERSION 3.14)
project(IMS_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(IMS_project main.cpp monthly_process.cpp monthly_process.h daily_process.cpp daily_process.h year_cycle.cpp year_cycle.h statistics.cpp statistics.h argument_parser.cpp argument_parser.h mean_intensity_of_sunlight_brno.cpp mean_intensity_of_sunlight_brno.h teoretical_incident_sunlight_brno.cpp teoretical_incident_sunlight_brno.h sunlight_brno.cpp sunlight_brno.h)
target_link_libraries(${PROJECT_NAME} m simlib)