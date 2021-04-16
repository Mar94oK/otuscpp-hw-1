cmake_minimum_required(VERSION 3.15)
project(otuscpp_hw_1)

set(CMAKE_CXX_STANDARD 17)

#using UTC time by default. Making default CMake behaviour explicit.
string(TIMESTAMP TODAY "%Y-%m-%dT%H:%M:%S")

message(STATUS "Build time is: ${TODAY}")

file(READ "Versioning.txt" version)

string(REGEX MATCH "HOMEWORK_MAJOR_NUMBER ([0-9]*)" _ ${version})
set(HOMEWORK_MAJOR_NUMBER ${CMAKE_MATCH_1})

string(REGEX MATCH "HOMEWORK_MINOR_NUMBER ([0-9]*)" _ ${version})
set(HOMEWORK_MINOR_NUMBER ${CMAKE_MATCH_1})

set(HOMEWORK_MINOR_NUMBER ${CMAKE_MATCH_1})

if (GITHUB_RUN_NUMBER)
    message(STATUS "Built system is GitActions!")
    set(HOMEWORK_BUILD_NUMBER ${GITHUB_RUN_NUMBER})
else()
    string(REGEX MATCH "HOMEWORK_BUILD_NUMBER ([0-9]*)" _ ${version})
    set(HOMEWORK_BUILD_NUMBER ${CMAKE_MATCH_1})
endif()

message(STATUS "GitHub RUN ID: ${GITHUB_RUN_NUMBER}")
message(STATUS "Build Number: ${HOMEWORK_BUILD_NUMBER}")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.cpp.in ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp)

add_executable(otuscpp_hw_1 main.cpp version.cpp version.h BuildNumber.h)
target_include_directories(otuscpp_hw_1 PRIVATE ${CMAKE_SOURCE_DIR} )





