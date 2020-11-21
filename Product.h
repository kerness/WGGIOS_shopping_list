//
// Created by kerness on 18.11.2020.
//

#ifndef WGGIOS_SHOPPING_LIST_PRODUCT_H
#define WGGIOS_SHOPPING_LIST_PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    int quantity;

public:
    Product();
    Product(std::string name);

    std::string getName();
    int getQuantity();

    void changeName(std::string name);
    void changeQuantity(int quantity);

};


#endif //WGGIOS_SHOPPING_LIST_PRODUCT_H
