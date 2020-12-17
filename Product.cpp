//
// Created by maciek on 16.12.2020.
//

#include "Product.h"

#include <iostream>

const std::string Product::_unit = "undefined";

Product::~Product() {

}

std::string Product::getName() {
    return _name;
}

std::string Product::getUnit() {
    return _unit;
}

int Product::getQuantity() {
    return _quantity;
}

void Product::setQuantity(int quantity) {
    this->_quantity = quantity;
}

void Product::setName(std::string &name) {
    this->_name = name;
}
