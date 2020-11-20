//
// Created by kerness on 18.11.2020.
//

#include <iostream>
#include <string>
#include <vector>

#include "Product.h"
#include "ShoppingList.h"






std::string getStringLine();
int getInt();

void addShoppingList(std::vector<ShoppingList>& list);
void showShoppingLists(std::vector<ShoppingList>& list);
void deleteShoppingList(std::vector<ShoppingList>& list);
void editShoppingList(std::vector<ShoppingList>& list);



int main() {

    int mainMenu;
    std::vector<ShoppingList> shoppingLists;

    do {



        std::cout << "\n------------------------ \n"
                     "|    _LISTA ZAKUPOW_    |\n"
                     "|    1. Dodaj liste     |\n"
                     "|    2. Edytuj liste    |\n"
                     "|     3. Usun liste     |\n"
                     "------------------------ \n"
                  << std::endl;
        mainMenu = getInt();

        switch (mainMenu) {

            case 1:
                addShoppingList(shoppingLists);
                break;
            case 2:
                showShoppingLists(shoppingLists);
                break;
            case 3:
                deleteShoppingList(shoppingLists);
                break;
            case 4:
                break;
            default:
                break;
        }


    }while (mainMenu != 0);




    return 0;
}

std::string getStringLine() {
    /*do modyfikacji*/
    std::string  line;
    std::getline(std::cin, line);
    return line;
}

int getInt() {
    /*raczej do usiniêcia*/
    std::string line;
    std::getline(std::cin, line);
    return atoi(line.c_str());
}

void addShoppingList(std::vector<ShoppingList>& list) {
    std::cout << "Podaj nazwe nowej listy: ";
    std::string newListName = getStringLine();
    ShoppingList newList(newListName);
    std::cout << "Nazwa nowej listy " << newList.getListName(); // for checking and debuging
    list.push_back(newList);
    std::cout << "\n\nDodano nowa liste '" << list.back().getListName()<< "' Aktualna liczba list to: " << list.size();
}

void deleteShoppingList(std::vector<ShoppingList>& list) {
    showShoppingLists(list);
    std::cout << "Podaj numer listy, ktora chcesz usunac: ";
    int pos = getInt();
    list.erase(list.begin() + pos); // usuwa element vecotra okreslony przez position
    std::cout << "Pomyslnie usunieto " << pos << "liste";
}


void showShoppingLists(std::vector<ShoppingList>& list) {
    std::cout << "Twoje aktualne listy zakupow:\n";
    for (int i = 0; i < list.size(); i++) {
        std::cout << i << ". " << list[i].getListName() << "\n";
    }
}

void editShoppingList(std::vector<ShoppingList>& list) {
    showShoppingLists(list);
    std::cout << "Podaj numer listy, ktora chcesz edytowac: ";
    

}

