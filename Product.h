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
    Product(std::string name, int quant);

    std::string getProductName();
    int getQuantity();


    // currently unused
    void changeProductName(std::string name);
    void changeQuantity(int quant);

};


#endif //WGGIOS_SHOPPING_LIST_PRODUCT_H
