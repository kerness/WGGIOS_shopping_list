//
// Created by kerness on 18.11.2020.
//

#include "ShoppingList.h"

ShoppingList::ShoppingList(std::string name) : listName(name), products(products)
{
}



std::string ShoppingList::getListName() {
    return listName;
}

void ShoppingList::addProduct(std::string name)
{
    // alokacja miejsca dla product
    Product* newProduct = new Product(name, 1);
    // wstawienie na koniec listy
    products.push_back(newProduct);

}


Product ShoppingList::getProduct()
{
    
    return *products.back();
}

Product ShoppingList::getProduct(int pos)
{

    return *products[pos];
}

int ShoppingList::getListSize()
{
    return products.size();
}
