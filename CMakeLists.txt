cmake_minimum_required(VERSION 3.26)
project(vscode)

set(CMAKE_CXX_STANDARD 14)

add_executable(vscode
        C++/SqList2.cpp
        C++/约瑟夫环/Ysf.cpp
        C++/线性栈表/Stack.cpp
        C++/线性表图书管理系统/Books.cpp)
