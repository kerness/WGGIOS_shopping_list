//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
// Version 3.0 - updated: 12.01.2020
//

#include "ShoppingList.h"
#include <iomanip>
#include "ProductPieces.h"
#include "ProductLiters.h"
#include "ProductWeight.h"
#include "ShoppingListError.h"
#include <vector>
#include <string>

// constructor
ShoppingList::ShoppingList(std::string &_name, int _capacity) : _name(_name), _capacity(_capacity), _elementsCounter(0) {
}

// destructor
ShoppingList::~ShoppingList() {
    for (auto & p : _products) {
        delete p;
    }
}

ShoppingList &ShoppingList::operator+=(const ShoppingList &source) {
    this->_capacity += source._capacity;
    this->_elementsCounter += source._elementsCounter;
    this->_name = "Merged_" + this->_name + "_" +source._name;

    for (int i = 0; i < source._products.size(); ++i) {
        auto productPointer = source._products[i];
        auto productName = source._products[i]->getName();
        this->createNewProduct(productPointer, source._products[i]->getQuantity(), productName);
    }
    return *this;
}

std::string ShoppingList::getShoppingListName() {
    return _name;
}

int ShoppingList::getElementsCounter() const {
    return _elementsCounter;
}

int ShoppingList::getDefaultCapacity() {
    return DEFAULT_CAPACITY;
}

void ShoppingList::addProduct(int categoryNum, const std::string &name, int quant) {
    /*adding new product to shopping list. User can decide which product will be crated*/
    if (_products.size() == _capacity) {
         printf("sys: shopping list if full!");
    }
    else {
        Product* productPointer;
        // switch statement - let user decide which inherited object will be created
        switch (categoryNum) {
            case 1:
                productPointer = new ProductPieces(name, quant);
                break;
            case 2:
                productPointer = new ProductWeight(name, quant);
                break;
            case 3:
                productPointer = new ProductLiters(name, quant);
                break;
            default:
                printf("sys: input out of range. try again");
                return;
        }
        _products.addBack(productPointer);
        _elementsCounter++;
    }
}

void ShoppingList::printListContents() {
    /*prints elements of a list*/
    if (_products.empty()) {
        std::cout << "sys: this list is empty.\n";
        return;
    }
    std::cout << "sys: '" << _name << "' shopping list has following elements:\n";
    std::cout << std::setfill('-') << std::setw(32) << "\n";
    try {
        for (int i = 0; i < this->_products.size(); ++i) {
            std::cout << i << std::setfill(' ');
            _products[i]->printDetails();
        }
    }
    catch (ContainerOutOfRange& con) {
        std::cerr << con.what();
    }

    std::cout << std::setfill('-') << std::setw(32) << "\n";
}

bool ShoppingList::isAnyProductEqual(ShoppingList &toCompare) {
    /*check if there is any product equal by name and unit in two shopping lists*/
    bool isAnyElementEqual = false;
    for (auto & p1 : this->_products) {
        for (auto & p2 : toCompare._products) {
            if (p1->getName() == p2->getName() &&
                p1->getUnit() == p2->getUnit() )
                isAnyElementEqual = true;
        }
    }
    return isAnyElementEqual;
}

bool ShoppingList::isEmpty() {
    /*check if list is empty*/
    if(_products.empty())
        return true;
    else
        return false;
}

void ShoppingList::moveProduct(ShoppingList &destination, int productIndex) {
    /*move product from one list to another*/
    destination._products.addBack(this->_products[productIndex]);
    // delete moved product
    this->_products.erase(this->_products.begin() + productIndex);
}

void ShoppingList::smartMergeLists(ShoppingList &toMerge) {
    /* smart list merge. find 'duplicates' (the same name and unit) and sum quantity */
    for (int i = 0; i < this->_products.size(); ++i) {
        for (int j = 0; j < toMerge._products.size(); ++j) {
            if (this->_products[i]->getUnit() == toMerge._products[j]->getUnit() &&
                this->_products[i]->getName() == toMerge._products[j]->getName() ) {
                this->_products[i]->setQuantity(this->_products[i]->getQuantity() + toMerge._products[j]->getQuantity());
                toMerge.deleteProduct(j); // delete duplicated product form toMerge
            }
        }
    }
    *this += toMerge;

}

void ShoppingList::createNewProduct(Product *type, int quantity, std::string &name) {
    /*create new product using virtual createNew by Product *type pointer*/
    _products.addBack(type->createNew(name, quantity));
}
void ShoppingList::deleteProduct(int index) {
    /*delete specified item for a list*/
    this->_products.erase(_products.begin() + index);
}