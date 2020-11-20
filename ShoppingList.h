//
// Created by kerness on 18.11.2020.
//

#ifndef WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
#define WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H

#include <string>
#include <vector>
#include "Product.h"
#include <list>

constexpr int LENGTH = 10;

class ShoppingList {

private:
    std::string listName;
    std::list<Product*> products;

public:
    // constructor
    ShoppingList(std::string name);
 

    std::string getListName();

    // to manage products
    void addProduct(std::string name);




};


#endif //WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
