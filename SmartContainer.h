//
// Created by Maciej Bąk on 12.01.2020
//

#ifndef SMARTCONTAINER_H
#define SMARTCONTAINER_H

#include <iostream> // size_t
#include "ContainerError.h"

template<typename T>
class SmartContainer {

private:
    // actual size of contaianer
    size_t _actualSize;
    // whole size of container = actual size + empty slots
    size_t _capacity;

    T* _container = nullptr;
public:
    // iterators for erase function
    using iterator = T*;
    using constIterator = const T*;

private:
    void setCapacity(size_t newCapacity) {
        /*memory reallocation*/
        T* newContainer = new T[newCapacity];
        // if we want to set capacity to smaller value set actual size of a container to a new Capacity
        if(newCapacity < _actualSize)
            _actualSize = newCapacity;
        // rewrite elements
        for(size_t i = 0; i < _actualSize; i++)
            newContainer[i] = _container[i];
        // change capacity
        _capacity = newCapacity;
        // delete old
        delete[] _container;
        // assign newContainer to class variable
        _container = newContainer;
    }

public:
    SmartContainer() : _actualSize(0), _capacity(0){
        // set capacity to 2 at the beginning
        setCapacity(2);
    }
    ~SmartContainer() {
        _container = nullptr;
    }
    iterator begin() {
        return _container;
    }
    constIterator begin() const {
        return  _container;
    }
    iterator end() {
        return _container + _actualSize;
    }
    constIterator end() const {
        return _container + _actualSize;
    }
    const T& operator[](size_t index) const {
        // const version of operator []
        if (index < 0 || index >= _actualSize) {
            throw ContainerOutOfRange();
        }
        return _container[index];
    }
    T& operator[](size_t index) {
        // non const version of []
        if (index < 0 || index >= _actualSize) {
            throw ContainerOutOfRange();
        }
        return _container[index];
    }
    void addBack(const T& newData) {
        // add new element at the end of container
        if (_actualSize >= _capacity) {
            setCapacity(2*_capacity + _capacity / 2);
        }
        _container[_actualSize] = newData;
        ++_actualSize;
    }
    void deleteBack() {
        // delete last element of container (if eny exists)
        if(_actualSize > 0) {
            _actualSize--;
            _container[_actualSize].~T(); // call destructor
        }
    }
    iterator erase(iterator pos) {
        // delete element at position given by pos and reduce actualSize by one
        pos->~T(); // call destructor for element to delete
        // copy all elements behind element to delete
        for(auto i = pos + 1; i!=end(); ++i) {
            *(i-1) = *i;
        }
        // reduce size
        --_actualSize;
        return pos;
    }
    void clearAll() {
        // call destructor for all objects in array and set actual size to zero
        for(size_t i = 0; i < _actualSize; i++)
            _container[i].~T();
        _actualSize = 0;
    }
    size_t size() const {
        // return actual size of container
        return _actualSize;
    }
    bool empty() {
        // check if container is empty
        if(_actualSize == 0)
            return true;
        return false;
    }
};
#endif //SMARTCONTAINER_H
