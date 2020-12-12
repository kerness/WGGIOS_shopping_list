/*
    Created by Maciej Bak on 18.11.2020.
    Geoinf, 400666
*/
#include "Product.h"

Product::Product(std::string name) : name(name) {
    quantity = 0;
}

Product::Product(std::string name, int quant) : name(name), quantity(quant) {
}

std::string Product::getProductName() {
    return name;
}

int Product::getQuantity() {
    return quantity;
}

void Product::changeProductName(std::string name) {
    this->name = name;
}

void Product::changeQuantity(int quant) {
    this->quantity = quant;
}

