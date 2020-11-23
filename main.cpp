//
// Created by kerness on 18.11.2020.
//

#include <iostream>
#include <iomanip> // setw, setfill
#include <string>
#include <vector>
#include "Product.h"
#include "ShoppingList.h"

/*
    TODO: Zrobiæ coœ z tym, ¿eby przy wbraniu listy ktora nie istnieje (albo zamiast int wpisze sie jakis inny znak) powinno sie dziac coœ m¹drego a nie tak jak teraz :)
*/


std::string getStringLine();
int getInt();
void addShoppingList(std::vector<ShoppingList>& list);
void deleteShoppingList(std::vector<ShoppingList>& list);
void editShoppingList(std::vector<ShoppingList>& list);
void showShoppingList(std::vector<ShoppingList>& list);
void printMainMenu();
void showShoppingLists(std::vector<ShoppingList>& list);

int main() {
    int mainMenu;
    std::vector<ShoppingList> shoppingLists;
    do {
        printMainMenu();
        mainMenu = getInt();

        switch (mainMenu) {
        case 1:
            addShoppingList(shoppingLists);
            break;
        case 2:
            if (!shoppingLists.empty()) // if not empty
                editShoppingList(shoppingLists);
            else {
                std::cout << "sys: you need to create shopping list first" << std::endl;
                break;
            }
            break;
        case 3:
            if (!shoppingLists.empty()) // if not empty
                deleteShoppingList(shoppingLists);
            else {
                std::cout << "sys: i have hothing to delete" << std::endl;
                break;
            }
            break;
        case 4:
            if (!shoppingLists.empty()) // if not empty
                showShoppingList(shoppingLists);
            else {
                std::cout << "sys: there is nothing here. firstly, cerate a list" << std::endl;
                break;
            }
            break;
        default:
            std::cout << "sys: you are not allowed to do it." << std::endl;
            mainMenu = 5;
            break;
        }

    } while (mainMenu != 0);
    return 0;
}

std::string getStringLine() {
    /*gets an string form std input
    allows to use spaces in input string*/
    std::string  line;
    std::getline(std::cin, line);
    return line;
}

int getInt() {
    /*gets an intiger form std input*/
    std::string line;
    std::getline(std::cin, line);
    return atoi(line.c_str());
}

void addShoppingList(std::vector<ShoppingList>& list) {
    /*allows to add a new shopping list*/
    std::cout << "sys: name for new list.\n\tINPUT: ";
    std::string newListName = getStringLine();
    ShoppingList newList(newListName);
    list.push_back(newList);
    std::cout << "sys: new list '" << list.back().getShoppingListName()<< "' was added successfully. active lists: " << list.size() << std::endl;
}

void showShoppingLists(std::vector<ShoppingList>& list) {
    /*show all existing shopping lists. Unused directly in main menu.*/
    std::cout << "sys: active shopping lists:\n";
    std::cout << std::setfill(char(196)) << std::setw(32) << "\n";
    for (int i = 0; i < list.size(); i++)
        std::cout << "\t" << i << ". " << list[i].getShoppingListName() << std::endl;
    std::cout << std::setfill(char(196)) << std::setw(32) << "\n" << std::endl;
}

void deleteShoppingList(std::vector<ShoppingList>& list) {
    /*allows to delete speciefied element of shopping list*/
    showShoppingLists(list);
    std::cout << "sys: choose number of an list which you are wanted to delete.\n\tINPUT: ";
    int pos = getInt();
    list.erase(list.begin() + pos);
    std::cout << "sys: '" << pos << "' was deleted successfully" << std::endl;
}

void editShoppingList(std::vector<ShoppingList>& list) {
    showShoppingLists(list);
    std::cout << "sys: choose the number of a list for editing.\n\tINPUT: ";
    int pos = getInt();
    if (list[pos].getDefaultCapacity() > list[pos].getElementsCounter())
    {
        std::cout << "sys: type the name for an item which you are going to add to the '" << list[pos].getShoppingListName() << "' shopping list\n\tINPUT: ";
        std::string newItemName = getStringLine();
        std::cout << "sys: set quantity of'" << newItemName << "'.\n\tINPUT: ";
        int quant = getInt();
        list[pos].addProduct(newItemName, quant);
    }
    else {
        std::cout << "sys: shopping list is full. you can't add more than 10 items." << std::endl;
        return;
    }
}

void showShoppingList(std::vector<ShoppingList>& list)
{
    showShoppingLists(list);
    std::cout << "sys: choose number of an list which you are wanted to show. \n\tINPUT: ";
    int pos = getInt();
    list[pos].printListProducts();
}

void printMainMenu() {
    // header
    std::cout << std::setfill(char(196)) << char(218) << std::setw(30) << char(191) << std::endl;
    std::cout << std::setfill(' ') << char(179) << std::setw(6) << "      the shoppig list" << std::setw(8) << char(179) << std::endl;
    std::cout << std::setfill('-') << char(179) << std::setw(30) << char(179) << std::endl;
    // menu contents
    std::cout << std::setfill(' ') << char(179) << std::setw(6) << "      1. add new " << std::setw(13) << char(179) << std::endl;
    std::cout << std::setfill(' ') << char(179) << std::setw(6) << "      2. edit existing " << std::setw(7) << char(179) << std::endl;
    std::cout << std::setfill(' ') << char(179) << std::setw(6) << "      3. delete existing " << std::setw(5) << char(179) << std::endl;
    std::cout << std::setfill(' ') << char(179) << std::setw(6) << "      4. show existing " << std::setw(7) << char(179) << std::endl;
    std::cout << std::setfill('-') << char(179) << std::setw(30) << char(179) << std::endl;
    std::cout << std::setfill(' ') << char(179) << std::setw(6) << "      choose action..." << std::setw(8) << char(179) << std::endl;
    std::cout << std::setfill(char(196)) << char(192) << std::setw(30) << char(217) << std::endl;
}


