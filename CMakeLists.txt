cmake_minimum_required(VERSION 3.16)
project(BakMaciej-etap3)

set(CMAKE_CXX_STANDARD 14)

add_executable(BakMaciej-etap3 main.cpp Product.cpp Product.h ShoppingList.cpp ShoppingList.h ProductPieces.cpp ProductPieces.h ProductWeight.cpp ProductWeight.h ProductLiters.cpp ProductLiters.h ShoppingListError.cpp ShoppingListError.h SmartContainer.cpp SmartContainer.h ContainerError.cpp ContainerError.h)