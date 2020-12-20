//
// Created by maciek on 16.12.2020.
//

#include "ProductWeight.h"
#include <iostream>
#include <iomanip>

void ProductWeight::printDetails() {
    std::cout << std::setw(20) << _name << "\t|\t" << _quantity << "\t|\t"  << _unit << std::endl;
}
Product *ProductWeight::createNew(std::string name, int quantity) {
    return new ProductWeight(name, quantity);
}