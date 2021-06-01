cmake_minimum_required(VERSION 3.19)
project(binarytree)

set(CMAKE_CXX_STANDARD 14)

add_executable(binarytree
        main.cpp
        main2.cpp
        sources/BinaryTree.hpp
        Test.cpp
        TestCounter.cpp
        )