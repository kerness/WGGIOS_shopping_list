//
// Created by kerness on 18.11.2020.
//

#ifndef WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
#define WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H

#include <string>
#include <vector>
#include "Product.h"

constexpr int LENGTH = 10;

class ShoppingList {

private:
    std::string listName;
    std::vector<Product *> productList {LENGTH};

public:
    ShoppingList(std::string name);
    ShoppingList(const ShoppingList &shoppingList);
    ~ShoppingList();

    std::string getListName();



};


#endif //WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
