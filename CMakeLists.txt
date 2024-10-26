cmake_minimum_required(VERSION 3.20)
project(TP1)

set(CMAKE_CXX_STANDARD 20)

add_executable(TP1 main.cpp
        Entree.cpp
        Entree.h
        Tableau.cpp
        Tableau.h
        Agenda.hpp
        Agenda.cpp)
