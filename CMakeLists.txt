cmake_minimum_required(VERSION 3.23)
project(laba2_test)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba2_test main.cpp DynamicArray.hpp LinkedList.hpp Sequence.hpp ArraySequence.hpp LinkedListSequence.hpp VectorSorter.hpp libs.hpp)
