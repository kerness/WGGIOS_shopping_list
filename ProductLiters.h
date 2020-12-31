//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
//

#ifndef PRODUCTLITERS_H
#define PRODUCTLITERS_H

#include "Product.h"

class ProductLiters : public Product{
protected:
    const std::string _unit;
public:
    explicit ProductLiters(std::string name = "undefined", int quantity = 0) : Product(std::move(name), quantity), _unit("liters") {}
    ~ProductLiters() override = default;
    void printDetails() override;
    Product* createNew(std::string name, int quantity) override;
};

#endif //PRODUCTLITERS_H