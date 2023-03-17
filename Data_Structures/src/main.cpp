//============================================================================
// Name        : DS_Assignment_1.cpp
// Author      : Ahmed Sherif Mohamed
// Version     :
// Copyright   : M7dsh yeslemo makani
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#define RESERVED		0xDEADBEEF

enum class Error {
	NO_ERROR, NO_MEMORY_ERROR
};

class Stack {

	public:
		//Stack();				//TODO: Make it dynamic in size
		Stack(const int&);
		Stack(const Stack&);
		~Stack();

		Error push(const int&);
		Error pop();
		int top();
		Error clear();
		Error replace(const int&, const int&);
		Error print();

		bool isEmpty() {
			return usedSize == 0;
		}

	private:
		int size;
		int usedSize;

		int *stackTop;
		int *stackBottom;
		int *stack;
};

//Stack::Stack() {
//	Stack(1);
//}

Stack::Stack(const int &i) :
		size { 0 }, usedSize { 0 }, stackTop { nullptr }, stackBottom { nullptr }, stack { nullptr } {
	this->size = i;
	this->stack = new int[this->size];

	if (this->stack != nullptr) {
		this->stackBottom = this->stack;
		this->stackTop = this->stack + size - 1;

		int i;
		for (i = 0; i < size; i++) {
			*(stack + i) = RESERVED;
		}
	}
}

Stack::Stack(const Stack &other) {

	int i;

	//TODO: check size before copy
//	if(this)

	for (i = 0; i < other.usedSize; i++) {
		*((this->stack) + i) = *(other.stack + i);
	}
}

Stack::~Stack() {
	if (this->stack != nullptr) {
		delete[] stack;
		this->stack = nullptr;
		this->stackTop = nullptr;
		this->stackBottom = nullptr;
	}
}

Error Stack::push(const int &i) {
	Error rtnError = Error::NO_ERROR;

	do {

		//TODO: make it dynamic size
		if ((usedSize < (size / 2)) == false) {
			//reserve
			//copy			size *=2
			//delete
		}

		// put data
		(this->usedSize)++;
		this->stackTop = (this->stack) + (this->usedSize) - 1;
		*(this->stackTop) = i;

	} while (0);

	return rtnError;
}

Error Stack::pop() {
	Error rtnError = Error::NO_ERROR;

	do {

		//TODO: make it dynamic size
//		if ((usedSize < (size / 2)) == false) {
//			//reserve
//			//copy			size /=2
//			//delete
//		}

		(*stackTop) = RESERVED;
		stackTop--;
		usedSize--;
	} while (0);

	return rtnError;
}

int Stack::top() {
	return (*stackTop);
}

Error Stack::clear() {
	Error rtnError = Error::NO_ERROR;

	do {

		int i;
		for (i = 0; i < usedSize; i++) {
			*(stack + i) = RESERVED;
		}
		usedSize = 0;
		stackTop = stack;
		stackBottom = stack;

	} while (0);

	return rtnError;
}

Error Stack::print() {
	Error rtnError = Error::NO_ERROR;

	do {

		int i;
		for (i = 0; i < usedSize; i++) {
			std::cout << *(stack + i) << "\t";
		}

		std::cout << std::endl;

	} while (0);

	return rtnError;
}

Error Stack::replace(const int &item, const int &anotherItem) {
	Error rtnError = Error::NO_ERROR;

	do {

		int i;
		for (i = 0; i < usedSize; i++) {
			if (*(stack + i) == item) {
				*(stack + i) = anotherItem;
			}
		}

		std::cout << std::endl;

	} while (0);

	return rtnError;
}

void replace(Stack &inputStack, const int &size, const int &item, const int &item2Replace) {
	int *temp = new int[size];

	int data, i = 0;
	while (inputStack.isEmpty() == false) {
		data = inputStack.top();

		if (data == item) {
			data = item2Replace;
		}

		temp[i] = data;
		i++;

		inputStack.pop();
	}

	int j;
	for (j = 0; j < i; j++) {
		inputStack.push(temp[i - j - 1]);
	}
}

int main() {

	int size = 7;
	Stack s(size);

	s.push(1);
	s.push(3);
	s.push(14);
	s.push(12);
	s.push(15);
	s.push(18);
	s.push(19);

	s.print();

	replace(s, size, 3, 5);
	s.print();

	return 0;
}
