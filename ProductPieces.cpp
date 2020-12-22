//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
//

#include "ProductPieces.h"
#include <iostream>
#include <iomanip>

void ProductPieces::printDetails() {
    std::cout << std::setw(20) <<  _name << "\t|\t" << _quantity/100 << "\t|\t"  << _unit << std::endl;
}
Product *ProductPieces::createNew(std::string name, int quantity) {
    /*creates new product*/
    return new ProductPieces(name, quantity);
}