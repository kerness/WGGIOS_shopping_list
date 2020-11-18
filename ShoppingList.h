//
// Created by kerness on 18.11.2020.
//

#ifndef WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
#define WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H

#include <string>
#include <vector>
#include "Product.h"

class ShoppingList {

private:
    std::string name;
    std::vector<Product *> productList {};

public:
    ShoppingList(std::string name);
    ShoppingList(const ShoppingList &shoppingList);
    ~ShoppingList();




};


#endif //WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
