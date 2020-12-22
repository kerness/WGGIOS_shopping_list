/*
    Created by Maciej Bąk on 18.11.2020.
    Geoinf, 400666
    ------------------------------------------------------------------------------
    Simple, console application created in C++ allows you to manage shopping lists.
    You are able to add, remove and edit your lists.
    ------------------------------------------------------------------------------
    *Version 2.0*
    Updated: 22.12.2020
    You are able to move products between lists, merge them and add different types of products (pcs, kg, l)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>          // setw, setfill
#include <limits>           // cin.ignore argument
#include <climits>          // INT_MAX
#include "ShoppingList.h"

// input functions
std::string getStringLine (bool isFile);
int getInt (bool isFile);
int getAndStoreFloat(bool isFile);
// main menu functions
void addShoppingList(std::vector<ShoppingList>& list);
void deleteShoppingList(std::vector<ShoppingList>& list);
void editShoppingList(std::vector<ShoppingList>& list);
void showShoppingList(std::vector<ShoppingList>& list);
void showShoppingLists(std::vector<ShoppingList>& list);
// submenu functions
void addProductToShoppingList(std::vector<ShoppingList>& list, int listPos);
void mergeShoppingLists(std::vector<ShoppingList>& list, int listToMerge);
void moveProductToAnotherShoppingList(std::vector<ShoppingList>& lists, int fromIndex);
// 'GUI' functions
void printMainMenu();
void printSubMenu();
// file input just for testing
bool fileInput(int argc, char *argv[]);

// variables for testing (reading input from a file)
bool isFileArgument = false;
std::ifstream testFile;

int main(int argc, char *argv[]) {
     // test mode - if file is passed as an argument to program isFileArgument = true.
     // that value changes behaviour of input functions - reading from file
     isFileArgument = fileInput(argc, argv);
     // program main loop
    std::vector<ShoppingList> shoppingLists;
    bool mainMenu = true;
    do {
        printMainMenu();
        int mainMenuNum = getInt(isFileArgument);
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
                    std::cout << "sys: there is nothing here. firstly, create a list" << std::endl;
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

std::string getStringLine(bool isFile) {
    /* gets a string form std input. allows to use spaces in input string.
     * update: check if ifFile is true - if yeas read input from file */
    std::string input;
    if(isFile) {
        testFile >> input;
        std::cout << input;
    }
    else {
        std::cin.ignore(INT_MAX, '\n'); // discard characters from std::cin input until reach INT_MAX or new line character
        std::getline(std::cin, input);
    }

    std::cout << std::endl;
    return input;
}

int getInt(bool isFile) {
    /* gets an integer form std input and checks if the input is int number.
     * If not returns -1. If succesfull returns input.
     * update: check if ifFile is true - if yeas read input from file */
    int intInput;
    if(isFile) {
        testFile >> intInput;
        std::cout << intInput;
        return intInput;
    }
    else {
        std::cin >> intInput;
        if (std::cin.fail()) { // returns true if std::cin isn't int
            std::cin.clear(); // clears error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skips other characters in line
            std::cout << "sys: an error occurred - undefined input. try again.\n";
            return -1; // to indicate input error
        }
        else {
            std::cout << std::endl;
            return intInput;
        }
    }
}

int getAndStoreFloat(bool isFile) {
    /* Gets float from input, multiply by 100 (to provide 2.5 kg 1.75l etc.), cast to int and return int
     * check if ifFile is true - if yeas read input from file */
    float floatInput;
    if(isFile) {
        testFile >> floatInput;
        std::cout << floatInput;
        floatInput *= 100;
        int floatAsInt = static_cast<int>(floatInput);  // static_cast ????
        std::cout << floatAsInt;
        return  floatAsInt;
    }
    else {
        std::cin >> floatInput;
        if (std::cin.fail()) { // returns true if std::cin isn't float
            std::cin.clear(); // clears error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skips other characters in line
            std::cout << "sys: an error occurred - undefined input. try again.\n";
            return -1; // to indicate input error
        }
        else {
            std::cout << std::endl;
            floatInput *= 100;
            int floatAsInt = static_cast<int>(floatInput);
            std::cout << floatAsInt;
            return  floatAsInt;
        }
    }
}

void addShoppingList(std::vector<ShoppingList>& list) {
    /*allows to add a new shopping list at the back of the list*/
    std::cout << "sys: choose name for the new list \n\tINPUT: ";
    std::string newListName = getStringLine(isFileArgument);
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
    /*allows to delete specified element of shopping list*/
    showShoppingLists(list);
    std::cout << "sys: choose number of an list which you are wanted to delete.\n\tINPUT: ";
    int pos = getInt(isFileArgument);
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
    int pos = getInt(isFileArgument);
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu
        std::cout << "sys: an error occurred - input out of range. try again." << std::endl;
        return;
    }
    list[pos].printListContents();
}


void editShoppingList(std::vector<ShoppingList>& list) {
    /* creates "list edit submenu" and allows user to add, move products and merge shopping lists */
    showShoppingLists(list);  // prints list of shopping lists
    std::cout << "sys: choose the number of a list for editing.\n\tINPUT: ";
    int pos = getInt(isFileArgument);
    std::cout << "sys: you are editing '" <<list[pos].getShoppingListName() << "' list." << std::endl;
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu
        std::cout << "sys: an error occurred - undefined input. try again." << std::endl;
        return;
    }
    bool subMenu = true;
    do {
        printSubMenu();
        int subMenuNum =getInt(isFileArgument);
        switch (subMenuNum) {
            case 1: //add product
                addProductToShoppingList(list, pos);
                break;
            case 2: // moving products
                moveProductToAnotherShoppingList(list, pos);
                break;
            case 3: // lists merging
                mergeShoppingLists(list, pos);
                break;
            case 4: // exit to main menu
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
    /* allows to add products to list. there are 3 item categories and user can choose one of them.
     * IMPORTANT: quantity numbers (floats and ints) are stored as value multiplied by 100 */
    if (list[listPos].getDefaultCapacity() > list[listPos].getElementsCounter()) {// if there is less than 10 elements
        //std::cout << "sys: you are editing '" <<list[listPos].getShoppingListName() << "' list." << std::endl;
        std::cout << "sys: there are three item categories. choose one which is the most suitable for your product" << std::endl;
        std::cout << "|" << std::setw(10) << " 1. pieces[pcs] |" << " 2. weight[kg] |" << " 3. liters[l] |" << std::endl;
        int categoryNum = getInt(isFileArgument);
        if (categoryNum == -1 || categoryNum > 3) { // check if input is out of an range. if yes:  returns to main menu
            std::cout << "sys: an error occurred - input out of range. try again." << std::endl;
            return;
        }
        std::cout << "sys: type the name for a new item\n\tINPUT: ";
        std::string newItemName = getStringLine(isFileArgument);
        std::cout << "sys: set quantity of'" << newItemName << "'.\n\tINPUT: ";
        int quant;
        if(categoryNum == 1)
            quant = getInt(isFileArgument) * 100; // storing quantity numbers as multiplied by 100
        else
            quant = getAndStoreFloat(isFileArgument);
        if(quant == -100 || quant == -1) { // error catch get functions returns -1 if input is unexpected. -100 because earlier getInt result value was multiplied by 100
            std::cout << "sys: undefined input. try again." << std::endl;
            return;
        }
        list[listPos].addProduct(categoryNum, newItemName, quant);
    }
    else {
        std::cout << "sys: shopping list is full. you can't add more than 10 items." << std::endl;
        return;
    }
}

void moveProductToAnotherShoppingList(std::vector<ShoppingList>& lists, int fromIndex) {
    /* moving products form one to another list */
    if(lists[fromIndex].isEmpty()) { // prevent from doing something with empty list
        std::cout << "sys: you can not move product from an empty list." << std::endl;
        return;
    }
    std::cout << "sys: choose number of a product to move product from '" << lists[fromIndex].getShoppingListName() << "'" << std::endl;
    lists[fromIndex].printListContents();
    int productToMove = getInt(isFileArgument);
    std::cout << "sys: choose number of a list to move selected product'" << std::endl;
    showShoppingLists(lists);
    int destinationIndex = getInt(isFileArgument);
    if(destinationIndex == fromIndex) { // prevent form moving product form THIS list to THIS list
        std::cout << "sys: you can not move product to the same list." << std::endl;
        return;
    }
    // moving product
    lists[fromIndex].moveProduct(lists[destinationIndex], productToMove);
}

void mergeShoppingLists(std::vector<ShoppingList>& list, int listToMerge) {
    /* merging shopping lists. In two options: if any product is equal (same name and unit) - sum quantity and delete form list to merge.
     * In other case just add lists by using overloaded += operator */
    if (list.size() < 2) {  // at least 2 lists are necessary for merging
        std::cout << "sys: you need to create at least two shopping lists to be able to merge" << std::endl;
        return;
    }
    std::cout << "sys: choose number of a list to merge with '" << list[listToMerge].getShoppingListName() << "'" << std::endl;
    showShoppingLists(list);
    printf("\tINPUT: ");
    int mergeWith = getInt(isFileArgument);
    if(listToMerge == mergeWith) { // avoid self-merging
        std::cout << "sys: you can not merge a list with the same list.\n";
        return;
    }
    if(list[mergeWith].isEmpty()) { // avoid merging with empty list
        std::cout << "sys: you can not merge a list with empty list.\n";
        return;
    }
    // check if any product is equal in lists to merge
    if (list[listToMerge].isAnyProductEqual(list[mergeWith])) {
        // if yes merging with method to add quantity of products with the same name and type
        list[listToMerge].smartMergeLists(list[mergeWith]);
    }
    else {
        // if not just use overloaded += operator (simply add one to another)
        list[listToMerge] += list[mergeWith];
    }
    std::cout << "'" << list[listToMerge].getShoppingListName() << "' was merged with '" << list[mergeWith].getShoppingListName() << "' " << std::endl;
    // delete list used to merge with list to merge
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
    // submenu contents
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      1. add new product"   << std::setw(6) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      2. move product "     << std::setw(8) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      3. merge lists"       << std::setw(10) << '|' << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      4. exit to main menu"             << std::setw(4) << '|' << std::endl; // TODO zmienić na return to main menu
    // footer
    std::cout << std::setfill('-') << '|' << std::setw(30)  << '|'                          << std::endl;
    std::cout << std::setfill(' ') << '|' << std::setw(6)   << "      choose action..."     << std::setw(8) << '|' << std::endl;
    std::cout << std::setfill('-') << '+' << std::setw(30)  << '+'                          << std::endl;
}



bool fileInput(int argc, char *argv[]) {
    /* program testing mode - reading input from a file */
    bool isOpen = false;
    if (argc > 1) {
        printf("\t\t********TEST MODE********\n");
        std::cout << "\t\ttest file:" << argv[argc-1] << std::endl;
        testFile.open(argv[1]);
        if(testFile.is_open()) {
            printf("\t\ttest file is open\n\n");
            isOpen = true;
        }
    }
    return isOpen;
}