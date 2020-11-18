//
// Created by kerness on 18.11.2020.
//

#include <iostream>
#include <string>

#include "Product.h"
#include "ShoppingList.h"

void showShoppingLists();
void addShoppingList();
void editShoppingList(ShoppingList *shoppingList);
void deleteShoppingList(ShoppingList *shoppingList);

void addProductToList(ShoppingList *shoppingList, Product *product);

std::string getStringLine();


int main() {

    int mainMenu;
    do {

        std::cout << "------------------------ \n"
                     "|    _LISTA ZAKUPOW_    |\n"
                     "|    1. Pokaz listy     |\n"
                     "|    2. Utworz liste    |\n"
                     "|    3. Edytuj liste    |\n"
                     "|     4. Usun liste     |\n"
                     "------------------------ \n"
                  << std::endl;
        std::cin >> mainMenu;

        switch (mainMenu) {

            case 1:
                break;
            case 2:
                break;
            case 3:
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
    std::string  line;
    std::getline(std::cin, line);
    return line;
}
