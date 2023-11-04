#pragma once
#include <iostream>
#include "Container.h"
#include "Array.h"
using namespace std;

template <class T>
class Stack :public virtual Container<T> {
public:
	virtual T getTop() = 0;
	virtual void push(const T&) = 0;
	virtual T pop() = 0;
};



template <class T>
class StackAsArray : public Stack<T> {
public:
	Array<T> data;
	int count;

	// constructori
	StackAsArray(int size) : data(0, size), count(0) {};
	StackAsArray(const StackAsArray<T>& s) : data(s.data) {};

	T getTop() override{
		return data[count];
	}

	void push(const T& t) override{
		data.data[count] = t;
		count++;
	}

	T pop() override{
		return data[--count];
	}

	int getCount() override {
		return count;
	}

	int isEmpty() override {
		return count == 0;
	}

	int isFull() override {
		return data.getLength() == count;
	}
	
};





