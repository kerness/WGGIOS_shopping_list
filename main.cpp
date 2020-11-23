//
// Created by kerness on 18.11.2020.
//

#include <iostream>
#include <string>
#include <vector>

#include "Product.h"
#include "ShoppingList.h"

// input
std::string getStringLine();
int getInt();

void addShoppingList(std::vector<ShoppingList>& list);
void deleteShoppingList(std::vector<ShoppingList>& list);
void editShoppingList(std::vector<ShoppingList>& list);
void showShoppingList(std::vector<ShoppingList>& list);

// menu support
void showShoppingLists(std::vector<ShoppingList>& list);

int main() {

    int mainMenu;
    std::vector<ShoppingList> shoppingLists;

    do {

        std::cout << 
            "-----------------------------\n"
            "       LISTA ZAKUPOW\n"
            "-----------------------------\n"
            "       1. Dodaj liste\n"
            "       2. Edytuj liste\n"
            "       3. Usun liste\n"
            "       4. Wyswietl liste\n"
            << std::endl;

        mainMenu = getInt();

        switch (mainMenu) {

            case 1:
                addShoppingList(shoppingLists);
                break;
            case 2:
                editShoppingList(shoppingLists);
             
                break;
            case 3:
                deleteShoppingList(shoppingLists);
                break;
            case 4:
                showShoppingList(shoppingLists);
                
                break;
            default:
                break;
        }
    }while (mainMenu != 0);

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
    std::cout << "Podaj nazwe nowej listy: ";
    std::string newListName = getStringLine();
    ShoppingList newList(newListName);
    list.push_back(newList);
    std::cout << "Dodano nowa liste '" << list.back().getShoppingListName()<< "' Aktualna liczba list to: " << list.size() << std::endl;
}

void showShoppingLists(std::vector<ShoppingList>& list) {
    /*show all existing shopping lists. Unused directly in main menu.*/
    std::cout << "Twoje aktualne listy zakupow:\n";
    for (int i = 0; i < list.size(); i++) {
        std::cout << i << ". " << list[i].getShoppingListName() << std::endl;
    }
}

void deleteShoppingList(std::vector<ShoppingList>& list) {
    /*allows to delete speciefied element of shopping list*/
    showShoppingLists(list);
    std::cout << "Podaj numer listy, ktora chcesz usunac: ";
    int pos = getInt();
    list.erase(list.begin() + pos);
    std::cout << "Pomyslnie usunieto " << pos << "liste" << std::endl;
}

void editShoppingList(std::vector<ShoppingList>& list) {
    showShoppingLists(list);
    std::cout << "Podaj numer listy, ktora chcesz edytowac: " << std::endl;
    int pos = getInt();
    if (list[pos].getDefaultCapacity() > list[pos].getElementsCounter())
    {
        std::cout << "Podaj nazwe przedmiotu ktory chcesz dodac do listy '" << list[pos].getShoppingListName() << "': " << std::endl;
        std::string newItemName = getStringLine();
        std::cout << "Podaj ilos sztuk '" << newItemName << "':" << std::endl;
        int quant = getInt();
        list[pos].addProduct(newItemName, quant);
    }
    else {
        std::cout << "Nie mozesz dodac do listy wecej niz 10 produktow!" << std::endl;
        return;
    }
}

void showShoppingList(std::vector<ShoppingList>& list)
{
    showShoppingLists(list);
    std::cout << "Wybierz liste ktora chcesz wyswietlic: " << std::endl;
    int pos = getInt();

    list[pos].printListProducts();
}


