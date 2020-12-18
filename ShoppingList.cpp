//
// Created by maciek on 16.12.2020.
//
#include "ShoppingList.h"
#include <iomanip>
#include "ProductPieces.h"
#include "ProductLiters.h"
#include "ProductWeight.h"
#include <vector>

ShoppingList::ShoppingList(std::string &_name, int _capacity) : _name(_name), _capacity(_capacity), _elementsCounter(0) {
    //std::cout << "\t\t*system message* constructor is working!\n";
}
ShoppingList::~ShoppingList() {
    //std::cout << "\t\t*system message* destructor is working for '" << this->_name << "'\n";
    for (int i = 0; i < _products.size(); ++i) {
        //std::cout << _products[i]->getName() << "jest usuwany" << std::endl;
        delete _products[i];
    }
    std::vector<Product*>().swap(_products);
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
std::vector<Product*> ShoppingList::getProducts() {
    return _products;
}

void ShoppingList::addProduct(int categoryNum, const std::string &name, int quant) {
    if (_elementsCounter == _capacity)
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
        _elementsCounter++;
    }
}

void ShoppingList::printListContents() {  // TU BYL BUG NIE MOZNA KORZYSTAC Z _ELEMENST CIUNTR TYLKO  Z _PRODUCTS.SIZE!
//    if (_elementsCounter == 0) {
//        std::cout << "sys: this list is empty.\n";
//        return;
//    }
    if (_products.empty()) {
        std::cout << "sys: this list is empty.\n";
        return;
    }
    std::cout << "sys: '" << _name << "' shopping list has following elements:\n";
    std::cout << std::setfill('-') << std::setw(32) << "\n";
    //std::cout << std::setw(10) << std::setfill(' ') << "lp" << "\t|\t" << "name" << "\t|\t" << "quantity" << "\t|\t" << "category" << std::endl;
    for (int i = 0; i < _products.size(); ++i) {
        std::cout << i << std::setfill(' ');
        _products[i]->printDetails();
    }
    std::cout << std::setfill('-') << std::setw(32) << "\n";
}

void ShoppingList::mergeLists(ShoppingList& toMerge) {


}

ShoppingList &ShoppingList::operator+=(const ShoppingList &toMerge) {
    std::cout << "\t\t*system message* overloaded assignment operator is working!\n";

    if (this->_elementsCounter >= toMerge._elementsCounter) {
        for (int i = 0; i < this->_elementsCounter; ++i) {
            if (this->_products[i]->getName() == toMerge._products[i]->getName()) {
                this->_products[i]->setQuantity(this->_products[i]->getQuantity() + toMerge._products[i]->getQuantity());
            }
        }
    }
    else { //if this->_elementsCounter < toMerge._elementsCounter
        for (int i = 0; i < toMerge._elementsCounter; ++i) {
            if (this->_products[i]->getName() == toMerge._products[i]->getName()) {
                this->_products[i]->setQuantity(this->_products[i]->getQuantity() + toMerge._products[i]->getQuantity());
            }
        }
    }

    return *this;
}

void ShoppingList::moveProduct(ShoppingList &destination, int productIndex) {
    destination._products.push_back(this->_products[productIndex]);
    this->_products.erase(this->_products.begin() + productIndex);
//    // CHECKING
//    std::cout << "przeniesc z " << this->getShoppingListName() << std::endl;
//    std::cout << "przeniesc to " << this->_products[productIndex] << std::endl;
//    std::cout << "przeniesc do " << destination.getShoppingListName() << std::endl;
//    printf("przenies z po przeniesienuu\n");
//    this->printListContents();
//    printf("przenies do przeniesieniu\n");
//    destination.printListContents();
}

bool ShoppingList::isEmpty() {

    if(_products.empty())
        return true;
    else
        return false;
}
