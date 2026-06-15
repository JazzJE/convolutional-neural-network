cmake_minimum_required(VERSION 3.15)
project(cnn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(cnn 
    src/main.cpp
    src/ConvolutionalNetwork.cpp
    "tests/matrix_tests.cpp")

target_include_directories(cnn PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)