//
// Created by kerness on 18.11.2020.
//


#include "ShoppingList.h"
#include <iostream>


// constructor

ShoppingList::ShoppingList(std::string _name, int _capacity) : name(_name), capacity(_capacity), countElements(0)
{
	std::cout << "		system message: constructor is working!\n";
	products = new Product[capacity];
}


// copy construcotr
ShoppingList::ShoppingList(const ShoppingList& source)
{
	std::cout << "		system message: copy constructor is working!\n";

	this->name = source.name;
	this->countElements = source.countElements;
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
	std::cout << "		system message: overloaded assigment operator is working!\n";

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
	this->countElements = source.countElements;
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
	std::cout << "		system message: destructor is working for '" << this->name << "' of adress #" << this << "\n";
	delete[] products;
}

void ShoppingList::addProduct(const std::string& name)
{
	if (countElements == capacity) {
		std::cout << "Shopping lis if full!";
	}
	else {
		products[countElements] = name;
		countElements++;
	}
}


void ShoppingList::printListProducts() {
	std::cout << "'" << name << "' shopping list has following elements:\n";
	for (int i = 0; i < countElements; ++i) {
		std::cout << i << ". " << products[i].getName() << std::endl;
	}
}

std::string ShoppingList::getName()
{
	return name;
}


int ShoppingList::getCountElements()
{
	return countElements;
}



















//#include "ShoppingList.h"
//#include <iostream>
//
//// konstruktor zwyk³y
//ShoppingList::ShoppingList(std::string name) : name(name)
//{
//	products = new Product[maxElements];
//}
//
//// konstruktor kopiujacy
//ShoppingList::ShoppingList(const ShoppingList& sl)
//{
//	name = sl.name;
//	products = new Product[maxElements];
//	for (int i = 0; i < maxElements; ++i) {
//		products[i] = sl.products[i];
//
//	}
//	std::cout << "Dziala konstruktor kopiujacy";
//}
//
//
//// kopiuj¹cy operator przypisania
//ShoppingList& ShoppingList::operator=(const ShoppingList& sl)
//{
//	if (&sl != this) {
//
//		delete[] products;
//
//		name = sl.name;
//		products = new Product[maxElements];
//		for (int i = 0; i < maxElements; ++i) {
//			products[i] = sl.products[i];
//		}
//	}
//	std::cout << "Pracuje operator przypisania =";
//	return *this;
//}
//
//// destruktor
//ShoppingList::~ShoppingList()
//{
//	delete[] products;
//}
//
//// pozosta³e metody
//
//void ShoppingList::addProduct(Product newProduct)
//{
//	if (productsCount < maxElements) products[productsCount++] = newProduct;
//}
//
//
//std::string ShoppingList::getName()
//{
//	return name;
//}
//
//
