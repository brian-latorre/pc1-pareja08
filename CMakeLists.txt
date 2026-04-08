cmake_minimum_required(VERSION 3.10)
project(MinStackPC1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp src/solution.cpp)
add_executable(tests tests/tests.cpp src/solution.cpp)
add_executable(benchmark bench/benchmark.cpp src/solution.cpp)
