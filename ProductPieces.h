//
// Created by maciek on 16.12.2020.
//

#ifndef SHOPPING_LIST_PRODUCTPIECES_H
#define SHOPPING_LIST_PRODUCTPIECES_H
#include "Product.h"

class ProductPieces : public Product{
public:
protected:
    static const std::string _unit;

public:
    ProductPieces(std::string name = "undefined", int quantity = 0) : Product(name, quantity) {}
    ~ProductPieces(){}
    void printDetails() override;
    Product* createNew(std::string name, int quantity) override;
};

#endif //SHOPPING_LIST_PRODUCTPIECES_H
