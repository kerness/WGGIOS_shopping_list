//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
//

#include "ProductWeight.h"
#include <iostream>
#include <iomanip>

void ProductWeight::printDetails() {
    // cast float to int and divide by 100
    float quantityAsFloat = static_cast<float>(_quantity)/100;
    std::cout << std::fixed << std::setprecision(2) << std::setw(20) << _name << "\t|\t" << quantityAsFloat << "\t|\t"  << _unit << std::endl;
}
Product *ProductWeight::createNew(std::string name, int quantity) {
    /*creates new product*/
    return new ProductWeight(name, quantity);
}