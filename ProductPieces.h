//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
//

#ifndef PRODUCTPIECES_H
#define PRODUCTPIECES_H

#include "Product.h"

class ProductPieces : public Product{
protected:
    const std::string _unit;
public:
    explicit ProductPieces(std::string name = "undefined", int quantity = 0) : Product(std::move(name), quantity), _unit("pieces") {}
    ~ProductPieces() override = default;
    void printDetails() override;
    Product* createNew(std::string name, int quantity) override;
};

#endif //PRODUCTPIECES_H