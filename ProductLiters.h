//
// Created by maciek on 16.12.2020.
//

#ifndef SHOPPING_LIST_PRODUCTLITERS_H
#define SHOPPING_LIST_PRODUCTLITERS_H
#include "Product.h"

class ProductLiters : public Product{
protected:
    static const std::string _unit;

public:
    ProductLiters(std::string name = "undefined", int quantity = 0) : Product(name, quantity) {}
    ~ProductLiters(){}
    void printDetails() override;
    Product* createNew(std::string name, int quantity) override;
};

#endif //SHOPPING_LIST_PRODUCTLITERS_H
