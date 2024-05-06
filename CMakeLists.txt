cmake_minimum_required(VERSION 3.28)
project(Projeto_da_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projeto_da_2
        data_structures/MutablePriorityQueue.h
        data_structures/Graph.h
        data_structures/Heap.h
        data_structures/Heap.cpp
        data_structures/UFDS.cpp
        data_structures/UFDS.h
        src/main.cpp
        src/Data.cpp
        src/Data.h
        src/Menu.h
        src/Menu.cpp)

