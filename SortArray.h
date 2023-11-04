#pragma once
#include <iostream>
#include <algorithm>
#include "Array.h"
using namespace std;


template <class T>
class SortArray :public Array<T> {
public:
    SortArray() : Array<T>() {}
    SortArray(unsigned int base, unsigned int length) : Array<T>(base, length) {}
    int findValue(const T& value);
    SortArray& addValue(T const& newValue);
    SortArray& removeValue(T const& value);
    SortArray& merge(SortArray<T> const& array);
    SortArray& operator+(T const& value);
    SortArray& operator+(SortArray<T> const& arr);
};


template <class T>
int SortArray<T>::findValue(const T& value) {
    int left = this->base, right = this->length;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (this->data[mid] == value) {
            return mid;
        }
        else if (this->data[mid] > value) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

template <class T>
SortArray<T>& SortArray<T>::addValue(T const& value) {
    T* newData = new T[this->length + 1];
    int i;
    for (i = 0; i < this->length && this->data[i] < value; ++i) {
        newData[i] = this->data[i];
    }
    newData[i] = value;
    for (; i < this->length; ++i) {
        newData[i + 1] = this->data[i];
    }

    delete[]this->data;
    this->data = newData;
    this->length++;
    return *this;
}

template <class T>
SortArray<T>& SortArray<T>::removeValue(T const& value) {
    T* newData = new T[this->length - 1];
    int i;
    for (i = 0; i < this->length && this->data[i] != value; ++i) {
        newData[i] = this->data[i];
    }

    for (; i < this->length - 1; ++i) {
        newData[i] = this->data[i + 1];
    }
    delete[]this->data;
    this->data = newData;
    this->length--;
    return *this;
}

template <class T>
SortArray<T>& SortArray<T>::merge(SortArray<T> const& arr) {
    T* newData = new T[this->length + arr.length];
    int i = 0, j = 0, c = 0;
    while (i < this->length && j < arr.length) {
        if (this->data[i] == arr.data[j]) {
            newData[c] = this->data[i];
            c++;
            newData[c] = arr.data[j];
            i++;
            j++;
            c++;
        }
        else if (this->data[i] < arr.data[j]) {
            newData[c] = this->data[i];
            i++;
            c++;
        }
        else {
            newData[c] = arr.data[j];
            j++;
            c++;
        }
    }
    while (i < this->length) {
        newData[c] = this->data[i];
        i++;
        c++;
    }
    while (j < arr.length) {
        newData[c] = arr.data[j];
        j++;
        c++;
    }
    delete[]this->data;
    this->data = newData;
    this->length = this->length + arr.length;
    return *this;
}

template <class T>
SortArray<T>& SortArray<T>::operator+(T const& value) {

    return addValue(value);
}

template <class T>
SortArray<T>& SortArray<T>::operator+(SortArray<T> const& arr) {
    for (int i = 0; i < arr.length; ++i) {
        addValue(arr[i]);
    }
    return *this;
}