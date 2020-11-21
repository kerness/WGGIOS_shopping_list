//
// Created by kerness on 18.11.2020.
//

#include "Product.h"

Product::Product()
{
	quantity = 1;
}

Product::Product(std::string name) : name(name)
{
	quantity = 1;
}

std::string Product::getName() {
	return name;
}
int Product::getQuantity() {
	return quantity;
}

void Product::changeName(std::string name)
{
	this->name = name;
}

void Product::changeQuantity(int quantity)
{
	this->quantity = quantity;
}



