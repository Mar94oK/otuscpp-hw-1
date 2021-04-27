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

if (BUILD_NUMBER)
    set(HOMEWORK_BUILD_NUMBER ${BUILD_NUMBER})
else()
    string(REGEX MATCH "HOMEWORK_BUILD_NUMBER ([0-9]*)" _ ${version})
    set(HOMEWORK_BUILD_NUMBER ${CMAKE_MATCH_1})
endif()

#Obviously, this is crutch. I don't know hot to make this more beautifull.
#It is necessary to pass this environment variable to the post-build bash script.
#But it is up to Cmake to define this value on the run...
#What to do???
file(WRITE binary_version.txt "${HOMEWORK_MAJOR_NUMBER}_${HOMEWORK_MINOR_NUMBER}_${HOMEWORK_BUILD_NUMBER}")

message(STATUS "Build Number: ${HOMEWORK_BUILD_NUMBER}")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.cpp.in ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp)

add_executable(helloworld main.cpp version.cpp version.h BuildNumber.h)
target_include_directories(helloworld PRIVATE ${CMAKE_SOURCE_DIR} )

set(HW1_EXECUTION_TEST_TIMEOUT 1)

enable_testing()

add_test(ExecutionTest helloworld)

set_tests_properties(ExecutionTest PROPERTIES TIMEOUT ${HW1_EXECUTION_TEST_TIMEOUT})

set_tests_properties(ExecutionTest PROPERTIES
        PASS_REGULAR_EXPRESSION "build [0-9]"
        FAIL_REGULAR_EXPRESSION "Error!")




