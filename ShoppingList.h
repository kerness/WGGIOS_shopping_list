//
// Created by maciek on 16.12.2020.
//

#ifndef SHOPPING_LIST_SHOPPINGLIST_H
#define SHOPPING_LIST_SHOPPINGLIST_H


#include "Product.h"
#include "ProductPieces.h"
#include "ProductWeight.h"
#include "ProductLiters.h"
#include <iostream>
#include <vector>
#include <string>

// TODO zamienić _products.size() na metodę


class ShoppingList {

private:
    static const int DEFAULT_CAPACITY = 10;
    int _elementsCounter;
    int _capacity;
    std::string _name;
    std::vector<Product*> _products;

public:
    // constructor
    explicit ShoppingList(std::string& name, int cap = DEFAULT_CAPACITY);
    // copy constructor
    //ShoppingList(const ShoppingList& source);
    // overloaded '=' operator
    //ShoppingList& operator=(const ShoppingList& source);
    // destructor
    ~ShoppingList();
    ShoppingList& operator+=(const ShoppingList& source);
    std::string getShoppingListName();
    int getElementsCounter();
    int getDefaultCapacity() const;
    void addProduct(int categoryNum, const std::string& name, int quant);
    void printListContents();
    void moveProduct(ShoppingList& destination, int productIndex);
    void smartMergeLists(ShoppingList& toMerge);
    void createNewProduct(Product* type, int quantity, std::string& name);
    bool isAnyProductEqual(ShoppingList& toCompare);
    bool isEmpty();
    void deleteProduct(int index);

    void deleteProductByPointer(Product* toDelete);
    //std::vector<Product*> getProduct(int index);
};

#endif //SHOPPING_LIST_SHOPPINGLIST_H
