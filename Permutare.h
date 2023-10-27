#pragma once
#include <iostream>
#include "Array.h"
using namespace std;

class Permutare {
protected:
	Array<unsigned int> data;
	unsigned int grad;
public:
	Permutare(unsigned int);
	Permutare(Permutare const& perm);
	Permutare(Array<unsigned int> const& arr, unsigned int grad);
	Permutare& setIdentic();
	Permutare& setReverse();
	Permutare& operator=(const Permutare& p);
	Permutare& operator*(const Permutare& p);
	Permutare& operator++();
	unsigned int getGrad() {
		return grad;
	}
	void getData() {
		for (int i = 1; i <= grad; ++i) {
			cout << data[i] << ' ';
		}
	}
	void interschimba(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
};


Permutare::Permutare(unsigned int grad): grad(grad), data(1, grad){}

Permutare::Permutare(Permutare const& perm) : data(perm.data), grad(perm.grad){}

	
Permutare::Permutare(Array<unsigned int> const& arr, unsigned int grad): data(arr), grad(grad) {}

Permutare& Permutare::setIdentic() {
	for (int i = 1; i <= grad; ++i) {
		data[i] = i;
	}
	return *this;
}

Permutare& Permutare::operator=(const Permutare& p) {
	if (this != &p) {
		delete []data.data;
		grad = p.grad;
		data.data = new unsigned int[grad];
		data = p.data;
	}
	return *this;
}

Permutare& Permutare::setReverse() {
	for (int i = 1; i <= grad; ++i) {
		data[i] = grad - i + 1;
	}
	return *this;
}

// compunere
Permutare& Permutare::operator*(const Permutare& p) {
	for (int i = 1; i <= grad; ++i) {
		data[i] = p.data[data[i]];
	}
	return *this;
}

// @TODO: implement the method
Permutare& Permutare::operator++() {
	// cautam de la dreapta spre stanga cel mai mare sir descrescator
	int lungime = grad;
	while (data[lungime] < data[lungime - 1] && lungime > 1) {
		lungime--;
	}
	// daca exista succesor
	if (lungime > 1) {
		int lungime2 = grad;
		while (data[lungime - 1] > data[lungime2]) {
			lungime2--;
		}
	}
	return *this;
}