//
// Created by maciek on 16.12.2020.
//

#ifndef SHOPPING_LIST_PRODUCT_H
#define SHOPPING_LIST_PRODUCT_H
#include <string>

class Product {
protected:
    std::string _name;
    //static const std::string _unit;
    std::string _unit;
    int _quantity;
public:
    explicit Product(std::string name = "unknown", int quantity = 0) : _name(name), _quantity(quantity), _unit("undefined") {}
    virtual ~Product();
    std::string getName();
    std::string getUnit();
    int getQuantity();
    void setQuantity(int quantity);
    void setName(std:: string& name);
    virtual void printDetails() = 0;

    virtual Product* createNew(std::string name, int quantity) = 0;

};

#endif //SHOPPING_LIST_PRODUCT_H
