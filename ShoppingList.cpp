//
// Created by kerness on 18.11.2020.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(std::string name) : listName(name)
{
}


std::string ShoppingList::getListName() {
    return listName;
}

void ShoppingList::addProduct(std::string name)
{
    // alokacja miejsca dla product
    Product* newProduct = new Product(name);
    // wstawienie na koniec listy
    products.push_back(newProduct);
}

