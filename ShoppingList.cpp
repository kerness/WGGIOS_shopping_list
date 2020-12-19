//
// Created by maciek on 16.12.2020.
//
#include "ShoppingList.h"
#include <iomanip>
#include "ProductPieces.h"
#include "ProductLiters.h"
#include "ProductWeight.h"
#include <vector>
#include <string>

ShoppingList::ShoppingList(std::string &_name, int _capacity) : _name(_name), _capacity(_capacity), _elementsCounter(0) {
}
ShoppingList::~ShoppingList() {
    for (auto & p : _products) {
        delete p;
    }
    std::vector<Product*>().swap(_products);
}
ShoppingList &ShoppingList::operator+=(const ShoppingList &source) {
    this->_capacity += source._capacity;
    this->_elementsCounter += source._elementsCounter;
    this->_name = "Merged_" + this->_name + "_" +source._name;

    for (int i = 0; i < source._products.size(); ++i) {
        auto productPointer = this->_products[i];
        auto productName = source._products[i]->getName();
        this->createNewProduct(productPointer, source._products[i]->getQuantity(), productName);
    }
    return *this;
}
std::string ShoppingList::getShoppingListName() {
    return _name;
}
int ShoppingList::getElementsCounter() {
    return _elementsCounter;
}
int ShoppingList::getDefaultCapacity() const {
    return DEFAULT_CAPACITY;
}
void ShoppingList::addProduct(int categoryNum, const std::string &name, int quant) {
    //if (_elementsCounter == _capacity)
    if (_products.size() == _capacity)
        printf("sys: shopping list if full!");
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
        _products.push_back(productPointer);
        //_elementsCounter++;
    }
}
void ShoppingList::printListContents() {
    if (_products.empty()) {
        std::cout << "sys: this list is empty.\n";
        return;
    }
    std::cout << "sys: '" << _name << "' shopping list has following elements:\n";
    std::cout << std::setfill('-') << std::setw(32) << "\n";
    for (int i = 0; i < this->_products.size(); ++i) {
        std::cout << i << std::setfill(' ');
        _products[i]->printDetails();
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
    if(_products.empty())
        return true;
    else
        return false;
}
void ShoppingList::moveProduct(ShoppingList &destination, int productIndex) {
    destination._products.push_back(this->_products[productIndex]);
    this->_products.erase(this->_products.begin() + productIndex);
}
void ShoppingList::smartMergeLists(ShoppingList &toMerge) {
    // dumb merge list first
    *this += toMerge;
    // find duplicates and sum quantity
    for (auto & p1 : this->_products) {
        for (auto & p2 : toMerge._products) {
            if (p1->getUnit() == p2->getUnit() &&
                p1->getName() == p2->getName() ) {
                p1->setQuantity(p1->getQuantity() + p2->getQuantity());
            }
        }
    }
}
void ShoppingList::createNewProduct(Product *type, int quantity, std::string &name) {
    _products.push_back(type->createNew(name, quantity));
}
void ShoppingList::deleteProduct(int index) {
    this->_products.erase(_products.begin() + index);
}