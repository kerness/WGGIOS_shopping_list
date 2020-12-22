//
// Created by Maciej Bąk on 18.11.2020.
// Version 2.0 - updated: 22.12.2020
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <utility>

class Product {
protected:
    std::string _name;
    std::string _unit;
    int _quantity;
public:
    explicit Product(std::string name = "unknown", int quantity = 0) : _name(std::move(name)), _quantity(quantity), _unit("undefined") {}
    virtual ~Product()= default;
    std::string getName();
    std::string getUnit();
    int getQuantity() const;
    void setQuantity(int quantity);
    void setName(std:: string& name);

    virtual void printDetails() = 0; // for printing
    virtual Product* createNew(std::string name, int quantity) = 0; // to create new Product
};

#endif // PRODUCT_H
