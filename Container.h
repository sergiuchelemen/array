#pragma once

template <class T>
class Container {
public:
	virtual int getCount() = 0;
	virtual int isEmpty() = 0;
	virtual int isFull() = 0;
};