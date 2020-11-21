//
// Created by kerness on 18.11.2020.
//

#include "Product.h"

Product::Product()
{
}

Product::Product(std::string name) : productName(name)
{
}

Product::Product(std::string name, int quant) : productName(name), quantity(quant)
{
}

std::string Product::getProductName()
{
	return productName;
}

int Product::getProductQuantity()
{
	return quantity;
}

void Product::changeQuantity(int quantity)
{
	this->quantity = quantity;
}

