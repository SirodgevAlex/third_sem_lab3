cmake_minimum_required(VERSION 3.23)
project(third_sem_lab3)

find_package(termcolor)

set(CMAKE_CXX_STANDARD 14)

add_executable(third_sem_lab3 main.cpp Graph.h Test.h Menu.h GraphFunctions.h Colors.h)

target_link_libraries(third_sem_lab3 termcolor::termcolor)