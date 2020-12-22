//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
//

#include "Product.h"

std::string Product::getName() {
    return _name;
}

std::string Product::getUnit() {
    return _unit;
}

int Product::getQuantity() const {
    return _quantity;
}

void Product::setQuantity(int quantity) {
    this->_quantity = quantity;
}

void Product::setName(std::string &name) {
    this->_name = name;
}
