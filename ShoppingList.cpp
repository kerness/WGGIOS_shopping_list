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

