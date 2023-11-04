#pragma once
#include <iostream>
#include "Container.h"
#include "Array.h"
using namespace std;

template <class T>
class Queue : public virtual Container<T> {
public:
	virtual T getHead() = 0;
	virtual void enQueue(const T) = 0;
	virtual T deQueue() = 0;
};

template <class T>
class QueueAsArray : public Queue<T> {
public:
	Array<T> data;
	int head, tail, count;
	QueueAsArray(int size) : data(0, size), count(0), head(0), tail(size - 1) {};
	QueueAsArray(const QueueAsArray<T>& q) : data(q.data), head(q.head), tail(q.tail), count(q.count) {};

	T getHead() {
		if (count == 0) {
			cout << "Coada plina!";
		}
		else {
			return data[head];
		}
	}

	void enQueue(const T t) {
		if (count == data.getLength()) {
			cout << "Coada plina!";
		}
		else {
			if (++tail == data.getLength()) {
				tail = 0;
			}
			data[tail] = t;
			count++;
		}
	}

	T deQueue(){
		if (count == 0){ 
			cout << "Coada plina!"; 
		}
		else {
			T result = data[head];
			if (++head == data.getLength()){
				head = 0; 
			}	
			--count;
			return result;
		}
	}

	int isEmpty(){
		return (count == 0);
	}
	int isFull(){
		return (count == data.getLength());
	}
	int getCount() {
		return count;
	}

	template <class T>
	friend ostream& operator<< (ostream&, const QueueAsArray<T>&);
};


template <class T>
ostream& operator<<(ostream& print, const QueueAsArray<T>& q) {
	for (int i = q.head; i <= q.tail; ++i) {
		print << q.data[i] << ' ';
	}
	return print;
}