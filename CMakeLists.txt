cmake_minimum_required(VERSION 3.16)
project(shopping_list)

set(CMAKE_CXX_STANDARD 14)

add_executable(shopping_list main.cpp Product.cpp Product.h ShoppingList.cpp ShoppingList.h ProductPieces.cpp ProductPieces.h ProductWeight.cpp ProductWeight.h ProductLiters.cpp ProductLiters.h theShoppingList.cpp theShoppingList.h)