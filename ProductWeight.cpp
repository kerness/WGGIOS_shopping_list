//
// Created by maciek on 16.12.2020.
//

#include "ProductWeight.h"
#include <iostream>

const std::string ProductWeight::_unit = "kilograms";

void ProductWeight::printDetails() {
    std::cout << _name << "\t|\t" << _quantity << " " << _unit << std::endl;
}
Product *ProductWeight::createNew(std::string name, int quantity) {
    return new ProductWeight(name, quantity);
}
