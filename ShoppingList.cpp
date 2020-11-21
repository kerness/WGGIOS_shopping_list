//
// Created by kerness on 18.11.2020.
//

#include "ShoppingList.h"
#include <iostream>

// konstruktor zwyk³y
ShoppingList::ShoppingList(std::string name) : name(name)
{
	products = new Product[maxElements];
}

// konstruktor kopiujacy
ShoppingList::ShoppingList(const ShoppingList& sl)
{
	name = sl.name;
	products = new Product[maxElements];
	for (int i = 0; i < maxElements; ++i) {
		products[i] = sl.products[i];

	}
	std::cout << "Dziala konstruktor kopiujacy";
}


// kopiuj¹cy operator przypisania
ShoppingList& ShoppingList::operator=(const ShoppingList& sl)
{
	if (&sl != this) {

		delete[] products;

		name = sl.name;
		products = new Product[maxElements];
		for (int i = 0; i < maxElements; ++i) {
			products[i] = sl.products[i];
		}
	}
	std::cout << "Pracuje operator przypisania =";
	return *this;
}

// destruktor
ShoppingList::~ShoppingList()
{
	delete[] products;
}

// pozosta³e metody

void ShoppingList::addProduct(Product newProduct)
{
	if (productsCount < maxElements) products[productsCount++] = newProduct;
}


std::string ShoppingList::getName()
{
	return name;
}


