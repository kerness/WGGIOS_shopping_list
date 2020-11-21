//
// Created by kerness on 18.11.2020.
//

#ifndef WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
#define WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H

#include "Product.h"
#include <string>
#include <vector>

class ShoppingList {
private:
    std::string name;
    Product *products;
    int productsCount = -1;
    enum {maxElements = 10};
public:
    ShoppingList(std::string name);
    ShoppingList(const ShoppingList& sl);
    ShoppingList & operator=(const ShoppingList& sl); 
    ~ShoppingList();

    void addProduct(Product newProduct);
    

    std::string getName();

};
#endif //WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
