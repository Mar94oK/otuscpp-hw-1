cmake_minimum_required(VERSION 3.15)
project(otuscpp_hw_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(otuscpp_hw_1 main.cpp version.h version.cpp BuildNumber.h)

target_include_directories(otuscpp_hw_1 PRIVATE ${CMAKE_SOURCE_DIR} )

#using UTC time by default. Making default CMake behaviour explicit.
string(TIMESTAMP TODAY "%Y-%m-%dT%H:%M:%S")

message(STATUS "Build time is: ${TODAY}")

file(READ "Versioning.txt" version)

string(REGEX MATCH "VERSION_MAJOR ([0-9]*)" _ ${version})
set(HOMEWORK_MAJOR_NUMBER ${CMAKE_MATCH_1})

string(REGEX MATCH "VERSION_MINOR ([0-9]*)" _ ${version})
set(HOMEWORK_MINOR_NUMBER ${CMAKE_MATCH_1})




