cmake_minimum_required(VERSION 3.8)

#set the project name
project(treealt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

#add the executable
add_executable(testavl TestAvlTree.cpp)

add_executable(testbinheap TestBinaryHeap.cpp)


