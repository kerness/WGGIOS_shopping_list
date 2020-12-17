//
// Created by maciek on 16.12.2020.
//

#ifndef SHOPPING_LIST_PRODUCTWEIGHT_H
#define SHOPPING_LIST_PRODUCTWEIGHT_H
#include "Product.h"



class ProductWeight : public Product{
protected:
    static const std::string _unit;

public:
    ProductWeight(std::string name = "undefined", int quantity = 0) : Product(name, quantity) {}
    ~ProductWeight(){}
    void printDetails() override;
    Product* createNew(std::string name, int quantity) override;
};

#endif //SHOPPING_LIST_PRODUCTWEIGHT_H
