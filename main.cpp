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
void deleteShoppingList(std::vector<ShoppingList>& list);
void editShoppingList(std::vector<ShoppingList>& list);
void showShoppingList(std::vector<ShoppingList>& list);
//
//// pomocnicza do menu
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
    std::cout << "Dodano nowa liste '" << list.back().getName()<< "' Aktualna liczba list to: " << list.size() << std::endl;
}

void showShoppingLists(std::vector<ShoppingList>& list) {
    /*show all existing shopping lists. Unused directly in main menu.*/
    std::cout << "Twoje aktualne listy zakupow:\n";
    for (int i = 0; i < list.size(); i++) {
        std::cout << i << ". " << list[i].getName() << std::endl;
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
    std::cout << "Podaj nazwe przedmiotu ktory chcesz dodac do listy '" << list[pos].getName() << "': " << std::endl;
    std::string newItemName = getStringLine();
    list[pos].addProduct(newItemName);
   /* std::cout << "Podaj ilos sztuk '" << list[pos]. << "':" << std::endl;
    int quant = getInt();
    list[pos].getProduct().changeQuantity(quant);
    std::cout << "Pomyslnie dodano '" << list[pos].getProduct().getProductName() << "' w ilosci " << quant << " sztuk." << std::endl;*/

}


void showShoppingList(std::vector<ShoppingList>& list)
{
    showShoppingLists(list);
    std::cout << "Wybierz liste ktora chcesz wyswietlic: " << std::endl;
    int pos = getInt();

    list[pos].printListProducts();


    //for (int i = 0; i < list[pos].getCountElements(); ++i) {

    //    std::string name = list[pos].pr
    //    int quant = list[pos].getProduct(i).getProductQuantity();

    //    std::cout << i << ". " << name << " - " << quant << " sztuk" << std::endl;
    //}

}


