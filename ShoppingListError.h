//
// Created by Maciej Bąk on 12.01.2020
//

#ifndef SHOPPINGLISTERROR_H
#define SHOPPINGLISTERROR_H

#include <iostream>

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
        _message = std::move(msg);
    }
};

struct TooLarge : public ShoppingListError {
    explicit TooLarge(std::string& name)
    : ShoppingListError(name) {
        _message = "shopping list is full. you can't add more than 10 items";
        _shoppingListName = name;
        _message = "'" + _shoppingListName + "' : " + _message;
    }
};
#endif //SHOPPINGLISTERROR_H