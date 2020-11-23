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
    int elementsCounter; 
    int capacity;
    static const int DEFAULT_CAPACITY = 10;
    
public:
    // constructor
    ShoppingList(std::string name, int cap = DEFAULT_CAPACITY);
    // copy constructor
    ShoppingList(const ShoppingList& source);
    // overloaded '=' operator
    ShoppingList& operator=(const ShoppingList& source);
    // destructor
    ~ShoppingList();

    void addProduct(const std::string& name, int quant);
    void printListProducts(); // TODO nielogiczna nazwa
    std::string getShoppingListName();
    int getElementsCounter(); 
    Product getProducts();
    int getDefaultCapacity() const;
};
#endif //WGGIOS_SHOPPING_LIST_SHOPPINGLIST_H
