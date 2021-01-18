//
// Created by Maciej Bąk on 12.01.2020
//

#ifndef CONTAINERERROR_H
#define CONTAINERERROR_H

#include <iostream>

struct ContainerError : public std::exception {
    std::string message;
    explicit ContainerError(std::string msg) : message(std::move(msg)) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

struct ContainerOutOfRange : public ContainerError {
    explicit ContainerOutOfRange(): ContainerError("range has been exceeded"){};
};

#endif //CONTAINERERROR_H