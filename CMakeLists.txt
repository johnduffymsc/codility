cmake_minimum_required(VERSION 3.0.0)

project(codility VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("/usr/local/include")

add_executable(ex1_longest_password ex1_longest_password.cpp)
add_executable(ex1_flood_depth ex1_flood_depth.cpp)

add_executable(ex5_parking_bill ex5_parking_bill.cpp)
add_executable(ex5_parity_degree ex5_parity_degree.cpp)
add_executable(ex5_three_letters ex5_three_letters.cpp)
