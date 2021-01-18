//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
// Version 3.0 - updated: 12.01.2020
//

#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H

#include "Product.h"
#include "ProductPieces.h"
#include "ProductWeight.h"
#include "ProductLiters.h"
#include "ShoppingListError.h"
#include "SmartContainer.h"
#include <iostream>
#include <vector>
#include <string>

class ShoppingList {

private:
    static const int DEFAULT_CAPACITY = 10;
    int _elementsCounter;
    int _capacity;
    std::string _name;
    SmartContainer<Product*> _products;

public:
    // constructor
    explicit ShoppingList(std::string& name, int cap = DEFAULT_CAPACITY);
    // destructor
    ~ShoppingList();
    // overloaded += operator
    ShoppingList& operator+=(const ShoppingList& source);
    // get something functions
    std::string getShoppingListName();
    int getElementsCounter() const;
    static int getDefaultCapacity() ;
    // product management functions
    void addProduct(int categoryNum, const std::string& name, int quant);
    void printListContents();
    void moveProduct(ShoppingList& destination, int productIndex);
    void smartMergeLists(ShoppingList& toMerge);
    void createNewProduct(Product* type, int quantity, std::string& name);
    void deleteProduct(int index);
    // checking functions
    bool isAnyProductEqual(ShoppingList& toCompare);
    bool isEmpty();
};

#endif // SHOPPING_LIST_H
