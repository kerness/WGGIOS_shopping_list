//
// Created by kerness on 18.11.2020.
//

#ifndef WGGIOS_SHOPPING_LIST_PRODUCT_H
#define WGGIOS_SHOPPING_LIST_PRODUCT_H

#include <string>

class Product {

private:
    std::string productName;
    int quantity;

public:
    Product();
    Product(std::string name);

    std::string getProductName();
    int getProductQuantity();

};


#endif //WGGIOS_SHOPPING_LIST_PRODUCT_H
