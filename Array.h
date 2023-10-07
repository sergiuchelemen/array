#pragma once
#include <iostream>
using namespace std;

template <class T>
class Array {
public:
    T* data;
    unsigned int length;
    unsigned int base;
public:
    Array();
    Array(unsigned int base = 0, unsigned int length = 0);
    Array(Array<T> const& array);
    Array& operator=(Array<T> const& array);
    T const& operator[](int pozitie) const;
    T& operator[](int pozitie);
    int getLength() const {
        return length;
    }
    int getBase() const {
        return base;
    }
    T const* getData() const {
        return data;
    }
    void setLenght(int newLength) {
        length = newLength;
    }
    void setBase(int newBase) {
        base = newBase;
    }
    void visit(void(&f)(T&));

};



template <class T>
Array<T>::Array() : data(new T[0]), length(0), base(0) {}

template <class T>
Array<T>::Array(unsigned int newBase, unsigned int newLength) : data(new T[newLength]), base(newBase), length(newLength) {}

// constructorul de copiere
template <class T>
Array<T>::Array(Array const& array) {
    if (this != &array) {
        delete[]data;
        base = array.base;
        length = array.length;
        data = new T[length];
        for (int i = 0; i < length; ++i) {
            data[i] = array.data[i];
        }
    }
}

// atribuire
template <class T>
Array<T>& Array<T>::operator=(Array const& array) {
    if (this != &array) {
        delete[]data;
        base = array.base;
        length = array.length;
        data = new T[length];
        for (int i = 0; i < length; ++i) {
            data[i] = array.data[i];
        }
        return *this;
    }
}



// r-value
template <class T>
T const& Array<T>::operator[](int pozitie) const {
    if (pozitie >= length) {
        cout << "Indexul depaseste lungimea vectorului!";
    }
    else {
        return data[pozitie];
    }
}

// l-value
template <class T>
T& Array<T>::operator[](int pozitie) {
    if (pozitie >= length) {
        cout << "Indexul depaseste lungimea vectorului!";
    }
    else {
        return data[pozitie];
    }
}

// iterator
template <class T>
void Array<T>::visit(void(&f)(T&)) {
    for (int i = 0; i < length; ++i) {
        f(data[i]);
    }
    cout << '\n';
}

void f(int& k)
{
    cout << k << ' ';
}