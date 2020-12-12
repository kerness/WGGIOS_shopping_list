/*
	Created by Maciej Bak on 18.11.2020.
	Geoinf, 400666
*/
#include "ShoppingList.h"
#include <iostream>
#include <iomanip> // setw, setfill

// constructor
ShoppingList::ShoppingList(std::string _name, int _capacity) : name(_name), capacity(_capacity), elementsCounter(0) {
	std::cout << "\t\t*system message* constructor is working!\n";
	products = new Product[capacity];
}

// copy construcotr
ShoppingList::ShoppingList(const ShoppingList& source) {
	std::cout << "\t\t*system message* copy constructor is working!\n";
	// copyig elements
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
ShoppingList& ShoppingList::operator=(const ShoppingList& source) {
	std::cout << "\t\t*system message* overloaded assignment operator is working!\n";

	// to avoid sl1 = sl1
	if (this == &source) {
		// nothing to do here so return
		return *this;
	}
	// in case sl1 = sl2
	// new array allocation
	delete[] products;
	products = new Product[capacity];
	// elements copying
	this->name = source.name;
	this->elementsCounter = source.elementsCounter;
	this->capacity = source.capacity;
	// array copying
	for (int i = 0; i < source.capacity; ++i)
		this->products[i] = source.products[i];
	return *this;
}

// destructor 
ShoppingList::~ShoppingList() {
	std::cout << "\t\t*system message* destructor is working for '" << this->name << "\n";
	delete[] products;
}

void ShoppingList::addProduct(const std::string& name, int quant) {
	// to avoid more than 10 (capacity)
	if (elementsCounter == capacity)
		std::cout << "sys: shopping lis if full!";
	else {
		products[elementsCounter].changeProductName(name);
		products[elementsCounter].changeQuantity(quant);
		elementsCounter++;
	}
}

void ShoppingList::printListContents() {
	if (elementsCounter == 0) {
		std::cout << "sys: this list is empty.\n";
		return;
	}
	std::cout << "sys: '" << name << "' shopping list has following elements:\n";
	std::cout << std::setfill('-') << std::setw(32) << "\n";
	for (int i = 0; i < elementsCounter; ++i)
		std::cout <<"\t" << i << ". " << products[i].getProductName() << "\t|\t" << products[i].getQuantity() <<std::endl;
	std::cout << std::setfill('-') << std::setw(32) << "\n";
}

std::string ShoppingList::getShoppingListName() {
	return name;
}

int ShoppingList::getElementsCounter() {
	return elementsCounter;
}
Product ShoppingList::getProducts() {
	return *products;
}

int ShoppingList::getDefaultCapacity() const {
	return DEFAULT_CAPACITY;
}
