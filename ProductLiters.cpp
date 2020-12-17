//
// Created by maciek on 16.12.2020.
//

#include "ProductLiters.h"
#include <iostream>
#include <iomanip>

const std::string ProductLiters::_unit = "liters";

void ProductLiters::printDetails() {
    std::cout << std::setw(10) << _name << "\t|\t" << _quantity << "\t|\t"  << _unit << std::endl;
}
Product *ProductLiters::createNew(std::string name, int quantity) {
    return new ProductLiters(name, quantity);
}