//
// Created by kerness on 18.11.2020.
//

#include "ShoppingList.h"
#include <iostream>
#include <iomanip> // setw, setfill

// constructor
ShoppingList::ShoppingList(std::string _name, int _capacity) : name(_name), capacity(_capacity), elementsCounter(0)
{
	std::cout << "\t\tsystem message: constructor is working!\n";
	products = new Product[capacity];
}

// copy construcotr
ShoppingList::ShoppingList(const ShoppingList& source)
{
	std::cout << "\t\tsystem message: copy constructor is working!\n";

	this->name = source.name;
	this->elementsCounter = source.elementsCounter;
	this->capacity = source.capacity;

	// allocating new Product to provide new memory adress
	this->products = new Product[source.capacity];
	// array copying
	for (int i = 0; i < source.capacity; ++i) {
		this->products[i] = source.products[i];
	}
}

// overloaded '=' operator
ShoppingList& ShoppingList::operator=(const ShoppingList& source)
{
	std::cout << "\t\tsystem message: overloaded assigment operator is working!\n";

	// to avoid sl1 = sl1
	if (this == &source)
	{
		// nothing to do here so return
		return *this;
	}
	// in case sl1 = sl2

	// new array
	delete[] products;
	products = new Product[capacity];

	this->name = source.name;
	this->elementsCounter = source.elementsCounter;
	this->capacity = source.capacity;

	// array copying
	for (int i = 0; i < source.capacity; ++i) {
		this->products[i] = source.products[i];
	}

	return *this;
}

// destructor 
ShoppingList::~ShoppingList()
{
	std::cout << "\t\tsystem message: destructor is working for '" << this->name << "' of adress #" << this << "\n";
	delete[] products;
}

void ShoppingList::addProduct(const std::string& name, int quant)
{
	if (elementsCounter == capacity) {
		std::cout << "shopping lis if full!";
	}
	else {
		products[elementsCounter].changeProductName(name);
		products[elementsCounter].changeQuantity(quant);
		elementsCounter++;
	}
}

void ShoppingList::printListProducts() {
	if (elementsCounter == 0) {
		std::cout << "sys: this list is empty.\n";
		return;
	}
	std::cout << "sys: '" << name << "' shopping list has following elements:\n";
	std::cout << std::setfill(char(196)) << std::setw(32) << "\n";
	for (int i = 0; i < elementsCounter; ++i) {
		std::cout <<"\t" << i << ". " << products[i].getProductName() << " | " << products[i].getQuantity() <<std::endl;
	}
	std::cout << std::setfill(char(196)) << std::setw(32) << "\n";
}

std::string ShoppingList::getShoppingListName()
{
	return name;
}

int ShoppingList::getElementsCounter()
{
	return elementsCounter;
}

Product ShoppingList::getProducts()
{
	return *products;
}

int ShoppingList::getDefaultCapacity() const
{
	return DEFAULT_CAPACITY;
}

