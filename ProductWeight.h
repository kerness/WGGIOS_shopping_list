//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
//

#ifndef PRODUCTWEIGHT_H
#define PRODUCTWEIGHT_H

#include "Product.h"

class ProductWeight : public Product{
protected:
    const std::string _unit;
public:
    explicit ProductWeight(std::string name = "undefined", int quantity = 0) : Product(std::move(name), quantity), _unit("kilograms") {}
    ~ProductWeight() override = default;
    void printDetails() override;
    Product* createNew(std::string name, int quantity) override;
};

#endif //PRODUCTWEIGHT_H