cmake_minimum_required(VERSION 3.10)

# Project name
project(Ray_Tracing_Project_Cpp)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Where to include headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect all cpp files automatically
file(GLOB SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Add executable
add_executable(Ray_Tracing_Project_Cpp ${SOURCES})