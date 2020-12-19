#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // setw, setfill
#include <limits> // cin.ignore argument
#include <climits> // INT_MAX
//#include <cmath>// floorf
#include "ShoppingList.h"





// TODO sprawdzanie poprawności wpisania liczb! ! ! ! !









// input functions
std::string getStringLine ();
int getInt ();
int getAndStoreFloat();
// user interaction functions
void addShoppingList(std::vector<ShoppingList>& list);
void deleteShoppingList(std::vector<ShoppingList>& list);
void editShoppingList(std::vector<ShoppingList>& list);
void showShoppingList(std::vector<ShoppingList>& list);
void showShoppingLists(std::vector<ShoppingList>& list);
void printMainMenu();
void printSubMenu();

void addProductToShoppingList(std::vector<ShoppingList>& list, int listPos);
void mergeShoppingLists(std::vector<ShoppingList>& list, int listToMerge); // nie działa
void moveProductToAnotherShoppingList(std::vector<ShoppingList>& lists, int fromIndex);

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

std::string getStringLine() {
    /*gets a string form std input
    allows to use spaces in input string*/
    std::cin.ignore(INT_MAX, '\n'); // discard characters from std::cin input until reach INT_MAX or new line character
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int getInt() {
    /*gets an intiger form std input
    and checks if the input is int nuber.
    If not returs -1. If succesfull returs input*/
    int intInput;
    std::cin >> intInput;
    if (std::cin.fail()) { // returns true if std::cin isn't int
        std::cin.clear(); // clears error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skips other characters in line
        std::cout << "sys: an error occurred - undefined input. try again.\n";
        return -1; // to indicate input error
    }
    else
        return intInput;
}

void addShoppingList(std::vector<ShoppingList>& list) {
    /*allows to add a new shopping list at the back of the list*/
    std::cout << "sys: choose name for the new list \n\tINPUT: ";
    std::string newListName = getStringLine();
    ShoppingList newList(newListName);
    list.push_back(newList);
    std::cout << "sys: new list '" << list.back().getShoppingListName()<< "' was added successfully. active lists: " << list.size() << std::endl;
}

void showShoppingLists(std::vector<ShoppingList>& list) {
    /*shows all existing shopping lists. Unused directly in main menu.*/
    std::cout << "sys: active shopping lists:\n";
    std::cout << std::setfill('-') << std::setw(32) << "\n";  // border
    for (int i = 0; i < list.size(); i++)
        std::cout << "\t" << i << ". " << list[i].getShoppingListName() << std::endl;
    std::cout << std::setfill('-') << std::setw(32) << "\n" << std::endl; // border
}

void deleteShoppingList(std::vector<ShoppingList>& list) {
    /*allows to delete speciefied element of shopping list*/
    showShoppingLists(list);
    std::cout << "sys: choose number of an list which you are wanted to delete.\n\tINPUT: ";
    int pos = getInt();
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu.
        std::cout << "sys: an error occurred - undefined input. try again." << std::endl;
        return;
    }
    list.erase(list.begin() + pos); // item deleting
    std::cout << "sys: '" << pos << "' was deleted successfully" << std::endl;
}

void showShoppingList(std::vector<ShoppingList>& list) {
    /*prints out contents (products) of shopping list */
    showShoppingLists(list);
    std::cout << "sys: choose number of an list which you are wanted to show. \n\tINPUT: ";
    int pos = getInt();
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu
        std::cout << "sys: an error occurred - input out of range. try again." << std::endl;
        return;
    }
    list[pos].printListContents();
}


void editShoppingList(std::vector<ShoppingList>& list) {
    /*allows to edit shopping list - by now, just adding new products*/
    showShoppingLists(list);  // prints list of shopping lists
    std::cout << "sys: choose the number of a list for editing.\n\tINPUT: ";
    int pos = getInt();
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu
        std::cout << "sys: an error occurred - undefined input. try again." << std::endl;
        return;
    }
    bool subMenu = true;
    do {
        printSubMenu();
        int subMenuNum =getInt();
        switch (subMenuNum) {
            case 1:
                addProductToShoppingList(list, pos);
                break;
            case 2:
                moveProductToAnotherShoppingList(list, pos);
                break;
            case 3:
                // TODO create merging here ! ! !
                mergeShoppingLists(list, pos);
                break;
            case 4:
                subMenu = false;
                break;
            default:
                std::cout << "sys: an error occurred - undefined input. try again." << std::endl;
                subMenu = false;
                break;
        }
    } while (subMenu);
}

void addProductToShoppingList(std::vector<ShoppingList>& list, int listPos) {
    if (list[listPos].getDefaultCapacity() > list[listPos].getElementsCounter()) {// if there is less than 10 elements
        std::cout << "sys: you are editing '" <<list[listPos].getShoppingListName() << "' list." << std::endl;
        std::cout << "sys: there are three item categories. choose one which is the most suitable for your product" << std::endl;
        std::cout << "|" << std::setw(10) << " 1. pieces[pcs] |" << " 2. weight[kg] |" << " 3. liters[l] |" << std::endl;
        int categoryNum = getInt();
        if (categoryNum == -1 || categoryNum > 3) { // check if input is out of an range. if yes:  returns to main menu
            std::cout << "sys: an error occurred - input out of range. try again." << std::endl;
            return;
        }

        std::cout << "sys: type the name for a new item\n\tINPUT: ";
        std::string newItemName = getStringLine();
        std::cout << "sys: set quantity of'" << newItemName << "'.\n\tINPUT: ";
        int quant = getInt();

        list[listPos].addProduct(categoryNum, newItemName, quant);
    }
    else {
        std::cout << "sys: shopping list is full. you can't add more than 10 items." << std::endl;
        return;
    }
}

void moveProductToAnotherShoppingList(std::vector<ShoppingList>& lists, int fromIndex) {
    if(lists[fromIndex].isEmpty()) { // prevent from doing something with empty list
        std::cout << "sys: you can not move product from an empty list." << std::endl;
        return;
    }
    std::cout << "sys: choose number of a product to move product from '" << lists[fromIndex].getShoppingListName() << "'" << std::endl;
    lists[fromIndex].printListContents();
    int productToMove = getInt();
    std::cout << "sys: choose number of a list to move selected product'" << std::endl;
    showShoppingLists(lists);
    int destinationIndex = getInt();
    if(destinationIndex == fromIndex) { // prevent form moving product form THIS list to THIS list
        std::cout << "sys: you can not move product to the same list." << std::endl;
        return;
    }
    lists[fromIndex].moveProduct(lists[destinationIndex], productToMove);
}

void mergeShoppingLists(std::vector<ShoppingList>& list, int listToMerge) {
    std::cout << "sys: choose number of a list to merge with '" << list[listToMerge].getShoppingListName() << "'" << std::endl;
    showShoppingLists(list);
    printf("\tINPUT: ");
    int mergeWith = getInt();
    std::cout << "łączę " << list[listToMerge].getShoppingListName() << " z " << list[mergeWith].getShoppingListName() << std::endl;
    if (list[listToMerge].isAnyProductEqual(list[mergeWith])) {
        // do smart merging with metod
        list[listToMerge].smartMergeLists(list[mergeWith]);
    }
    else {
        // do dumb merging with += operator
        list[listToMerge] += list[mergeWith];
    }
    list.erase(list.begin() + mergeWith);
}

void printMainMenu() {
    /*prints main menu of the program*/
    // header
    std::cout << std::setfill('-') << '+' << std::setw(30)  << '+'                          << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      the shopping list"     << std::setw(7) << '|' << std::endl;
    std::cout << std::setfill('-') << '|' << std::setw(30)  << '|'                          << std::endl;
    // menu contents
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      1. add new "          << std::setw(13) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      2. edit existing "    << std::setw(7) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      3. delete existing "  << std::setw(5) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      4. show existing "    << std::setw(7) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      5. exit "             << std::setw(16) << '|' << std::endl;
    // footer
    std::cout << std::setfill('-') << '|' << std::setw(30)  << '|'                          << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      choose action..."     << std::setw(8) << '|' << std::endl;
    std::cout << std::setfill('-') << '+' << std::setw(30)  << '+'                          << std::endl;
}

void printSubMenu() {
    /*prints edit submenu of the program*/
    // header
    std::cout << std::setfill('-') << '+' << std::setw(30)  << '+'                          << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      list edit submenu"    << std::setw(7) << '|' << std::endl;
    std::cout << std::setfill('-') << '|' << std::setw(30)  << '|'                          << std::endl;
    // menu contents
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      1. add new product"   << std::setw(6) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      2. move product "     << std::setw(8) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      3. merge lists"       << std::setw(10) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      4. exit "             << std::setw(16) << '|' << std::endl; // TODO zmienić na return to main menu
    // footer
    std::cout << std::setfill('-') << '|' << std::setw(30)  << '|'                          << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      choose action..."     << std::setw(8) << '|' << std::endl;
    std::cout << std::setfill('-') << '+' << std::setw(30)  << '+'                          << std::endl;
}

