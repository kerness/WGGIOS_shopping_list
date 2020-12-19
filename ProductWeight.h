//
// Created by maciek on 16.12.2020.
//

#ifndef SHOPPING_LIST_PRODUCTWEIGHT_H
#define SHOPPING_LIST_PRODUCTWEIGHT_H
//#include <utility>

#include "Product.h"

class ProductWeight : public Product{
protected:
    std::string _unit;
public:
    explicit ProductWeight(std::string name = "undefined", int quantity = 0) : Product(std::move(name), quantity), _unit("kilograms") {}
    ~ProductWeight() override = default;
    void printDetails() override;
    Product* createNew(std::string name, int quantity) override;
};

#endif //SHOPPING_LIST_PRODUCTWEIGHT_H
