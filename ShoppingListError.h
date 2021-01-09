//
// Created by maciek on 05.01.2021.
//

#ifndef BAKMACIEJ_ETAP2_SHOPPINGLISTERROR_H
#define BAKMACIEJ_ETAP2_SHOPPINGLISTERROR_H



#include <iostream>
#include <utility>

struct ShoppingListError : public std::exception {
    std::string _message;
    std::string _shoppingListName;
    explicit ShoppingListError(std::string name = "unknown", std::string msg = "shopping list error ")
    : _shoppingListName(std::move(name)), _message(std::move(msg)) {}

    const char* what() const noexcept override {
        return _message.c_str();
    }
};

struct NeitherExists : public ShoppingListError {
    explicit NeitherExists()
    : ShoppingListError() {
        _message = "neither shopping list exists";
    }
};

struct IsEmpty : public ShoppingListError {
    explicit IsEmpty(std::string msg)
            : ShoppingListError() {
        _message = msg;
    }
};

// napisac struktirę która będzie obsługiwała wyjątek gdy przy przektocczeniu limitu 10 elementów będzie mozna zdecydowac czy chce się taka listę zapisac czy też nie

struct TooLarge : public ShoppingListError {
    explicit TooLarge(std::string& name)
    : ShoppingListError(name) {
        _message = "shopping list is full. you can't add more than 10 items";
        _shoppingListName = name;
        _message = "'" + _shoppingListName + "' : " + _message;
    }

};





#endif //BAKMACIEJ_ETAP2_SHOPPINGLISTERROR_H
