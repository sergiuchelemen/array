#pragma once
#include "SortArray.h"


template <class T>
class Term {
public:
	T coeficient;
	int grad;
	Term() :coeficient(0), grad(0) {}
	Term(T c, int g = 0) : coeficient(c){
		if (c == 0.0) {
			grad = 0;
		}
		else {
			grad = g;
		}
	};
	Term(const Term<T>& t) {
		coeficient = t.coeficient;
		if (t.coeficient == 0.0) {
			grad = 0;
		}
		else {
			grad = t.grad;
		}
	}

	bool isNull() {
		return coeficient == 0.0;
	}

	bool operator >(const Term& b) {
		return grad > b.grad;
	}

	bool operator <(const Term& b) {
		return grad < b.grad;
	}

	bool operator >=(const Term& b) {
		return grad >= b.grad;
	}

	bool operator <=(const Term& b) {
		return grad <= b.grad;
	}

	bool operator ==(const Term& b) {
		return grad == b.grad;
	}

	bool equal(const Term& b) {
		return (grad == b.grad && coeficient == b.coeficient);
	}

	bool operator !=(const Term& b) {
		return grad != b.grad && coeficient != b.coeficient;
	}

	Term<T>& operator=(const Term& b) {
		grad = b.grad;
		coeficient = b.coeficient;
		return *this;
	}
};

template <class T>
class Polinom {
public:
	SortArray<Term<T>> data;
	int grad;
	
	// constructori
	Polinom() : grad(0), data(0, 0) {};
	Polinom(const Term<T>&);
	

	// metode
	Polinom<T>& addTerm(const Term<T>&);
	Polinom<T>& subTerm(Term<T>);
	Polinom<T>& addValue(T coeficient, int grad);
	Polinom<T>& subValue(T coeficient, int grad);
	Polinom<T>& operator=(const Term<T>&);
	Polinom<T>& operator=(const Polinom<T>&);
	Polinom<T>& operator+(const Term<T>&);
	Polinom<T>& operator+(const T);
	Polinom<T>& operator+(const Polinom<T>&);
	Polinom<T>& operator-(Term<T>&);
	Polinom<T>& operator-(const T);
	Polinom<T>& operator-(Polinom<T>&);
	Polinom<T>& operator*(const T&);
	Polinom<T>& operator*(Term<T>&);
	Polinom<T>& operator*(const Polinom<T>&);
	T evaluate(T);
	bool isNull() const{
		return data.getLength() == 0;
	}

	void afisare() {
		for (int i = 0; i < data.length; ++i) {
			cout << data[i].coeficient << "x la puterea " << data[i].grad << endl;
		}
	}
};




template <class T>
Polinom<T>::Polinom(const Term<T>& t) {
	grad = t.grad;
	data = data + t;
}


// metoda prin care adaugam un termen la polinom
// este clasa de baza pentru toate operatiile
template <class T>
Polinom<T>& Polinom<T>::addTerm(const Term<T>& t) {
	// cautam termenul in polinom
	int pos = data.findValue(t);
	// daca nu exista il adaugam
	if (pos < 0) {
		data + t;
		if (grad < t.grad) {
			grad = t.grad;
		}
	}
	else {
		// daca coeficientii adunati dau 0, inseamna ca termenul trebuie eliminat din polinom
		if (data[pos].coeficient + t.coeficient == 0.0) {
			data.removeValue(data[pos]);
			grad = data[data.getLength() - 1].grad;
		}
		else {
			data[pos].coeficient += t.coeficient;
		}
	}
	if (data.length == 0) {
		grad = 0;
	}
	return *this;
}


// cautam in polinom dupa grad daca exista elementul pe care vream sa-l eliminam
template <class T>
Polinom<T>& Polinom<T>::subTerm(Term<T> t) {
	t.coeficient = -t.coeficient;
	return addTerm(t);
}

template <class T>
Polinom<T>& Polinom<T>::addValue(T coeficient, int grad) {
	Term<T> t(coeficient, grad);
	return addTerm(t);
}

template <class T>
Polinom<T>& Polinom<T>::subValue(T coeficient, int grad) {
	Term<T> t(-coeficient, grad);
	return addTerm(t);
}

// supraincarcare operatori
template <class T>
Polinom<T>& Polinom<T>::operator=(const Term<T>& t) {
	// daca polinomul are termeni
	if (data.length != 0) {
		data.setLenght(0);
	}
	data = data + t;
	grad = t.grad;
	return *this;
}

template <class T>
Polinom<T>& Polinom<T>::operator=(const Polinom<T>& p) {
	if (this != &p) {
		data = p.data;
		grad = p.grad;
	}
	return *this;
}

template <class T>
Polinom<T>& Polinom<T>::operator+(const Term<T>& t) {
	return addTerm(t);
}

template <class T>
Polinom<T>& Polinom<T>::operator+(const T numar) {
	Term<T> t(numar);
	return addTerm(numar);
}

template <class T>
Polinom<T>& Polinom<T>::operator-(Term<T>& t){
	return subTerm(t);
}

template <class T>
Polinom<T>& Polinom<T>::operator-(const T numar) {
	Term<T> t(numar);
	return subTerm(t);
}

template <class T>
Polinom<T>& Polinom<T>::operator+(const Polinom<T>& p) {
	for (int i = 0; i < p.data.getLength(); ++i) {
		addTerm(p.data[i]);
	}
	return *this;
}

template <class T>
Polinom<T>& Polinom<T>::operator-(Polinom<T>& p){
	for (int i = 0; i < p.data.getLength(); ++i) {
		subTerm(p.data[i]);
	}
	return *this;
}

template <class T>
Polinom<T>& Polinom<T>::operator*(const T& constanta) {
	if (constanta == 0) {
		grad = 0;
		SortArray<Term<T>> newArray;
		delete[]data.data;
		data.data = newArray.data;
		data.setLenght(0);
	}
	else {
		for (int i = 0; i < data.getLength(); ++i) {
			data[i].coeficient *= constanta;
		}
	}
	return *this;
}


template <class T>
Polinom<T>& Polinom<T>::operator*(Term<T>& t) {
	if (t.isNull()) {
		grad = 0;
		SortArray<Term<T>> newArray;
		delete[]data.data;
		data.data = newArray.data;
		data.setLenght(0);
	}
	else {
		for (int i = 0; i < data.getLength(); ++i) {
			data[i].coeficient *= t.coeficient;
			data[i].grad += t.grad;
			if (data[i].grad > grad) {
				grad = data[i].grad;
			}
		}
	}
	return *this;
}

template <class T>
Polinom<T>& Polinom<T>::operator*(const Polinom<T>& p) {
	if (p.isNull()) {
		grad = 0;
	    SortArray<Term<T>> newArray;
		delete[]data.data;
		data.data = newArray.data;
		data.setLenght(0);
	}
	else {
		for (int i = 0; i < p.data.getLength(); ++i) {
			for (int j = 0; j < data.getLength(); ++j) {
				data[j].coeficient *= p.data[i].coeficient;
				data[j].grad += p.data[i].grad;
				if (data[j].grad > grad) {
					grad = data[j].grad;
				}
			}
		}
	}
	return *this;
}

template <class T>
T Polinom<T>::evaluate(T punct) {
	T res = 0.0;
	for (int i = 0; i < data.getLength(); ++i) {
		res += data[i].coeficient * pow(punct, data[i].grad);
	}
	return res;
}