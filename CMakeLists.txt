cmake_minimum_required(VERSION 3.15)

project(cnn)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# External libraries

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)

find_package(OpenMP REQUIRED)

# Program files

set(CNN_SOURCES
    src/main.cpp
    src/ConvNetwork/ConvolutionalNetwork.cpp
)

add_executable(cnn
    ${CNN_SOURCES}
)

add_executable(tests
    tests/tensor_tests.cpp
    tests/main.cpp)

target_include_directories(cnn PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ConvNetwork
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)

target_link_libraries(cnn PRIVATE
    raylib
    OpenMP::OpenMP_CXX
)

target_include_directories(tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ConvNetwork
    ${CMAKE_CURRENT_SOURCE_DIR}/external
)

target_link_libraries(tests PRIVATE
    raylib
    OpenMP::OpenMP_CXX
)