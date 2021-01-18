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

    *Version 3.0*
    Updated: 12.01.2021
    Exceptions handling and own vector-like class
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
std::string getStringLine (bool isFile, std::ifstream& file);
int getInt (bool isFile, std::ifstream& file);
int getAndStoreFloat(bool isFile, std::ifstream& file);
// main menu functions
void addShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile);
void deleteShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile);
void editShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile);
void showShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile);
void showShoppingLists(std::vector<ShoppingList>& list);
// submenu functions
void addProductToShoppingList(std::vector<ShoppingList>& list, int listPos, bool fileArg, std::ifstream& testFile);
void mergeShoppingLists(std::vector<ShoppingList>& list, int listToMerge, bool fileArg, std::ifstream& testFile);
void moveProductToAnotherShoppingList(std::vector<ShoppingList>& lists, int fromIndex, bool fileArg, std::ifstream& testFile);
// 'GUI' functions
void printMainMenu();
void printSubMenu();
// file input just for testing
bool fileInput(int argc, char *argv[], std::ifstream& file);

int main(int argc, char *argv[]) {
     // test mode - if file is passed as an argument to program isFileArgument = true.
     // that value changes behaviour of input functions - reading from file
    std::ifstream testFile;
    bool isFileArgument;
    isFileArgument = fileInput(argc, argv, testFile);
     // program main loop
    std::vector<ShoppingList> shoppingLists;
    bool mainMenu = true;
    do {
       try {
           printMainMenu();
           int mainMenuNum = getInt(isFileArgument, testFile);
           switch (mainMenuNum) {
               case 1:
                   addShoppingList(shoppingLists, isFileArgument, testFile);
                   break;
               case 2:
                   editShoppingList(shoppingLists, isFileArgument, testFile);
                   break;
               case 3:
                   deleteShoppingList(shoppingLists, isFileArgument, testFile);
                   break;
               case 4:
                   showShoppingList(shoppingLists, isFileArgument, testFile);
                   break;
               case 5:
                   mainMenu = false;
                   break;
               default:
                   std::cout << "sys: you are not allowed to do it." << std::endl; // other input
                   break;
           }
       }
       catch (NeitherExists& nExists) {
           std::cout << nExists.what();
           mainMenu = true;
       }
    } while (mainMenu);
    return 0;
}

std::string getStringLine(bool isFile, std::ifstream& file) {
    /* gets a string form std input. allows to use spaces in input string.
     * update: check if ifFile is true - if yeas read input from file */
    std::string input;
    if(isFile) {
        file >> input;
        std::cout << input;
    }
    else {
        std::cin.ignore(INT_MAX, '\n'); // discard characters from std::cin input until reach INT_MAX or new line character
        std::getline(std::cin, input);
    }

    std::cout << std::endl;
    return input;
}

int getInt(bool isFile, std::ifstream& file) {
    /* gets an integer form std input and checks if the input is int number.
     * If not returns -1. If succesfull returns input.
     * update: check if ifFile is true - if yeas read input from file */
    int intInput;
    if(isFile) {
        file >> intInput;
        std::cout << intInput;
        std::cout << std::endl;
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

int getAndStoreFloat(bool isFile, std::ifstream& file) {
    /* Gets float from input, multiply by 100 (to provide 2.5 kg 1.75l etc.), cast to int and return int
     * check if ifFile is true - if yeas read input from file */
    float floatInput;
    if(isFile) {
        file >> floatInput;
        std::cout << floatInput;
        floatInput *= 100;
        int floatAsInt = static_cast<int>(floatInput);  // static_cast ????
        std::cout << std::endl;
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
            std::cout << std::endl;
            return  floatAsInt;
        }
    }
}

void addShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile) {
    /*allows to add a new shopping list at the back of the list*/
    std::cout << "sys: choose name for the new list \n\tINPUT: ";
    std::string newListName = getStringLine(fileArg, testFile);
    ShoppingList newList(newListName);
    list.push_back(newList);
    std::cout << "sys: new list '" << list.back().getShoppingListName()<< "' was added successfully. active lists: " << list.size() << std::endl;
}

void showShoppingLists(std::vector<ShoppingList>& list) {
    /*shows all existing shopping lists. Unused directly in main menu.*/
    if(list.empty())
        throw NeitherExists();
    std::cout << "sys: active shopping lists:\n";
    std::cout << std::setfill('-') << std::setw(32) << "\n";  // border
    for (int i = 0; i < list.size(); i++)
        std::cout << "\t" << i << ". " << list[i].getShoppingListName() << std::endl;
    std::cout << std::setfill('-') << std::setw(32) << "\n" << std::endl; // border
}

void deleteShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile) {
    /*allows to delete specified element of shopping list*/
    if(list.empty())
        throw NeitherExists();
    showShoppingLists(list);
    std::cout << "sys: choose number of an list which you are wanted to delete.\n\tINPUT: ";
    int pos = getInt(fileArg, testFile);
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu.
        std::cout << "sys: an error occurred - undefined input. try again." << std::endl;
        return;
    }
    list.erase(list.begin() + pos); // item deleting
    std::cout << "sys: '" << pos << "' was deleted successfully" << std::endl;
}

void showShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile) {
    /*prints out contents (products) of shopping list */
    if(list.empty())
        throw NeitherExists();
    showShoppingLists(list);
    std::cout << "sys: choose number of an list which you are wanted to show. \n\tINPUT: ";
    int pos = getInt(fileArg, testFile);
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu
        std::cout << "sys: an error occurred - input out of range. try again." << std::endl;
        return;
    }
    list[pos].printListContents();
}


void editShoppingList(std::vector<ShoppingList>& list, bool fileArg, std::ifstream& testFile) {
    /* creates "list edit submenu" and allows user to add, move products and merge shopping lists */
    if(list.empty()) {
        throw NeitherExists();
    }
    showShoppingLists(list);  // prints list of shopping lists
    std::cout << "sys: choose the number of a list for editing.\n\tINPUT: ";
    int pos = getInt(fileArg, testFile);
    std::cout << "sys: you are editing '" <<list[pos].getShoppingListName() << "' list." << std::endl;
    if (pos == -1 || pos >= list.size()) { // check if input is out of an range. if yes:  returns to main menu
        std::cout << "sys: an error occurred - undefined input. try again." << std::endl;
        return;
    }
    bool subMenu = true;
    do {
        printSubMenu();
        try{
            int subMenuNum =getInt(fileArg, testFile);
            switch (subMenuNum) {
                case 1: //add product
                    addProductToShoppingList(list, pos, fileArg, testFile);
                    break;
                case 2: // moving products
                    moveProductToAnotherShoppingList(list, pos, fileArg, testFile);
                    break;
                case 3: // lists merging
                    mergeShoppingLists(list, pos, fileArg, testFile);
                    break;
                case 4: // exit to main menu
                    subMenu = false;
                    break;
                default:
                    std::cout << "sys: an error occurred - undefined input. try again." << std::endl;
                    subMenu = false;
                    break;
            }
        }
        catch (TooLarge& tl) {
            std::cout << tl.what();
        }
        catch (IsEmpty& ie) {
            std::cout << ie.what();
        }
    } while (subMenu);
}

void addProductToShoppingList(std::vector<ShoppingList>& list, int listPos, bool fileArg, std::ifstream& testFile) {
    /* allows to add products to list. there are 3 item categories and user can choose one of them.
     * IMPORTANT: quantity numbers (floats and ints) are stored as value multiplied by 100 */
    // check if list is empty or have more than 10 elements
    if(list.empty())
        throw NeitherExists();
    if(list[listPos].getDefaultCapacity() <= list[listPos].getElementsCounter()) {
        std::string listName = list[listPos].getShoppingListName();
        throw TooLarge(listName);
    }
    //std::cout << "sys: you are editing '" <<list[listPos].getShoppingListName() << "' list." << std::endl;
    std::cout << "sys: there are three item categories. choose one which is the most suitable for your product" << std::endl;
    std::cout << "sys: each category stores value in unit given inside []. " << std::endl;
    std::cout << "sys: for pieces you can use only integers. For weight and liters you can use double precision floating numbers." << std::endl;
    std::cout << "|" << std::setw(10) << " 1. pieces[pcs] |" << " 2. weight[kg] |" << " 3. liters[l] |" << std::endl;
    int categoryNum = getInt(fileArg, testFile);
    if (categoryNum == -1 || categoryNum > 3) { // check if input is out of an range. if yes:  returns to main menu
        std::cout << "sys: an error occurred - input out of range. try again." << std::endl;
        return;
    }
    std::cout << "sys: type the name for a new item\n\tINPUT: ";
    std::string newItemName = getStringLine(fileArg, testFile);
    std::cout << "sys: set quantity of'" << newItemName << "'.\n\tINPUT: ";
    int quant;
    if(categoryNum == 1)
        quant = getInt(fileArg, testFile) * 100; // storing quantity numbers as multiplied by 100
    else
        quant = getAndStoreFloat(fileArg, testFile);
    if(quant == -100 || quant == -1) { // error catch get functions returns -1 if input is unexpected. -100 because earlier getInt result value was multiplied by 100
        std::cout << "sys: undefined input. try again." << std::endl;
        return;
    }
    list[listPos].addProduct(categoryNum, newItemName, quant);
}



void moveProductToAnotherShoppingList(std::vector<ShoppingList>& lists, int fromIndex, bool fileArg, std::ifstream& testFile) {
    /* moving products form one to another list */
    if(lists[fromIndex].isEmpty()) { // prevent from doing something with empty list
        throw IsEmpty("sys: you can not move product from an empty list.");
    }
    std::cout << "sys: choose number of a product to move product from '" << lists[fromIndex].getShoppingListName() << "'" << std::endl;
    lists[fromIndex].printListContents();
    int productToMove = getInt(fileArg, testFile);
    std::cout << "sys: choose number of a list to move selected product" << std::endl;
    showShoppingLists(lists);
    int destinationIndex = getInt(fileArg, testFile);
    if(destinationIndex == fromIndex) { // prevent form moving product form THIS list to THIS list
        std::cout << "sys: you can not move product to the same list." << std::endl;
        return;
    }
    // moving product
    lists[fromIndex].moveProduct(lists[destinationIndex], productToMove);
}

void mergeShoppingLists(std::vector<ShoppingList>& list, int listToMerge, bool fileArg, std::ifstream& testFile) {
    /* merging shopping lists. In two options: if any product is equal (same name and unit) - sum quantity and delete form list to merge.
     * In other case just add lists by using overloaded += operator */
    if (list.size() < 2) {  // at least 2 lists are necessary for merging
        std::cout << "sys: you need to create at least two shopping lists to be able to merge" << std::endl;
        return;
    }
    std::cout << "sys: choose number of a list to merge with '" << list[listToMerge].getShoppingListName() << "'" << std::endl;
    showShoppingLists(list);
    printf("\tINPUT: ");
    int mergeWith = getInt(fileArg, testFile);
    if(listToMerge == mergeWith) { // avoid self-merging
        std::cout << "sys: you can not merge a list with the same list.\n";
        return;
    }
    if(list[mergeWith].isEmpty()) { // avoid merging with empty list
        throw IsEmpty("sys: you can not merge a list with empty list.\n");
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
    printf("\n");
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
    printf("\n");
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
bool fileInput(int argc, char *argv[], std::ifstream& file) {
    /* program testing mode - reading input from a file */
    bool isOpen = false;
    if (argc > 1) {
        file.open(argv[1]);
        if(file.is_open()) {
            isOpen = true;
            std::cout << "\t\t***********TEST MODE***********" << std::endl;
            std::cout << "\t\tfile has been attached" << std::endl;
            std::cout << "\t\treading file from : " << argv[argc-1]  << std::endl;
            std::cout << "\t\t*******************************" << std::endl;
        }
    }
    return isOpen;
}


