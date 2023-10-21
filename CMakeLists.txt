cmake_minimum_required(VERSION 2.8)
set(CURL_MIN_VERSION “7.28.0”)
 
# Setting up project
project(thetaData_cpp_wrapper)
 
#set c++ flags
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")
 
 
add_executable(thetaData_cpp_wrapper
main.cpp
client.cpp
)
 
#link curl and curlcpp
target_link_libraries(thetaData_cpp_wrapper curl)
