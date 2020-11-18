cmake_minimum_required(VERSION 3.16)
project(WGGIOS_shopping_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(WGGIOS_shopping_list main.cpp ShoppingList.cpp Product.cpp)