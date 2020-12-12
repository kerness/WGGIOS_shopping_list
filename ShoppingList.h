/*
    Created by Maciej Bak on 18.11.2020.
    Geoinf, 400666
*/
#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include "Product.h"
#include <string>
#include <iostream>
//#include <vector>

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
    void printListContents(); 
    std::string getShoppingListName();
    int getElementsCounter(); 
    Product getProducts();
    int getDefaultCapacity() const;
};
#endif //SHOPPINGLIST_H
