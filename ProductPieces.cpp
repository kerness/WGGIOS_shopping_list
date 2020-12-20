//
// Created by maciek on 16.12.2020.
//

#include "ProductPieces.h"
#include <iostream>
#include <iomanip>

void ProductPieces::printDetails() {
    std::cout << std::setw(20) <<  _name << "\t|\t" << _quantity << "\t|\t"  << _unit << std::endl;
}
Product *ProductPieces::createNew(std::string name, int quantity) {
    return new ProductPieces(name, quantity);
}