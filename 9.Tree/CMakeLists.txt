cmake_minimum_required(VERSION 3.28)
project(Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tree main.c tree.c
        tree.h ../Stack/stack.c ../Stack/stack.h)
