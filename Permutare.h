#pragma once
#include <iostream>
#include "Array.h"
using namespace std;

class Permutare {
protected:
	Array<unsigned int> data;
	unsigned int grad;
public:
	Permutare(unsigned int grad);
	Permutare(Permutare const& perm);
	Permutare(Array<unsigned int> const& arr, unsigned int grad);
	Permutare& setIdentic();
	Permutare& setReverse();
	Permutare& operator=(const Permutare& p);
	unsigned int getGrad() {
		return grad;
	}
	void getData() {
		for (int i = 1; i < data.getLength(); ++i) {
			cout << data[i] << ' ';
		}
	}
};

Permutare::Permutare(unsigned int grad): grad(grad), data(1, grad){
	for (int i = 1; i < grad; ++i) {
		data[i] = i;
	}
}

Permutare::Permutare(Permutare const& perm) : data(perm.data), grad(perm.grad){}

	
Permutare::Permutare(Array<unsigned int> const& arr, unsigned int grad): data(arr), grad(grad) {}

Permutare& Permutare::setIdentic() {
	for (int i = 1; i < grad; ++i) {
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
	for (int i = 1; i < grad; ++i) {
		data[i] = grad - i;
	}
	return *this;
}



