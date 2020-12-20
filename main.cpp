#include "ShoppingList.h"
#include "theShoppingList.h"
#include <iostream>
#include <vector>


// TODO sprawdzanie poprawności wpisania liczb! ! ! ! !

int main() {
    std::vector<ShoppingList> shoppingLists;
    bool mainMenu = true;
    do {
        printMainMenu();
        int mainMenuNum = getInt();
        switch (mainMenuNum) {
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
                    std::cout << "sys: i have nothing to delete" << std::endl;
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
            case 5:
                mainMenu = false;
                break;
            default:
                std::cout << "sys: you are not allowed to do it." << std::endl; // other input
                break;
        }
    } while (mainMenu);
    return 0;
}