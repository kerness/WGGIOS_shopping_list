//
// Created by maciek on 16.12.2020.
//

#include "ProductPieces.h"
#include <iostream>
#include <iomanip>

const std::string ProductPieces::_unit = "pieces";

void ProductPieces::printDetails() {
    std::cout <<std::setw(10) << _name << "\t|\t" << _quantity << " " << _unit << std::endl;
}
Product *ProductPieces::createNew(std::string name, int quantity) {
    return new ProductPieces(name, quantity);
}