/*
    Created by Maciej Bak on 18.11.2020.
    Geoinf, 400666
*/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    int quantity;

public:
    Product() : quantity(0) {}
    Product(std::string name);
    Product(std::string name, int quant);

    std::string getProductName();
    int getQuantity();
    void changeProductName(std::string name);
    void changeQuantity(int quant);
};
#endif //PRODUCT_H
