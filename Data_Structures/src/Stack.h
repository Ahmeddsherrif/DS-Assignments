/*
 * Stack.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Master
 */

#ifndef STACK_H_
#define STACK_H_


template<typename genericType>
class Stack {

	private:
		genericType *topPtr;
		genericType *bottomPtr;

		genericType *buffer;

		unsigned int size;
		unsigned int capacity;

	public:

		Stack(const unsigned int&);
		~Stack();

		void push(const genericType&);
		void pop();
		bool isEmpty();

		genericType top();

		void clear();
		void print();
};


template<typename genericType>
Stack<genericType>::Stack(const unsigned int &size) :
		topPtr { nullptr }, bottomPtr { nullptr }, buffer { nullptr }, size { size }, capacity { 0 } {

	this->buffer = new genericType[this->size]();

	assert(this->buffer != nullptr);

	this->bottomPtr = &(this->buffer)[0];
	this->topPtr = &(this->buffer)[0] - 1;
}

template<typename genericType>
Stack<genericType>::~Stack() {
	assert((this->buffer) != nullptr);

	delete[] (this->buffer);
	(this->buffer) = nullptr;
}

template<typename genericType>
void Stack<genericType>::push(const genericType &inputData) {

	assert((this->capacity) < (this->size));

	(this->topPtr)++;
	*(this->topPtr) = inputData;
	(this->capacity)++;
}

template<typename genericType>
void Stack<genericType>::pop() {

	assert(capacity > 0);

	(*topPtr) = genericType();
	capacity--;

	topPtr--;
}

template<typename genericType>
genericType Stack<genericType>::top() {
	assert(capacity > 0);

	return (*topPtr);
}


template<typename genericType>
bool Stack<genericType>::isEmpty(){
	return (capacity == 0);
}


template<typename genericType>
void Stack<genericType>::clear() {
	memset(buffer, 0, sizeof(genericType) * size);

	this->bottomPtr = &(this->buffer)[0];
	this->topPtr = &(this->buffer)[0] + 1;

	capacity = 0;
}

template<typename genericType>
void Stack<genericType>::print() {

	int i;
	for (i = 0; i < capacity; i++) {
		std::cout << *(buffer + i) << "\t";
	}
	std::cout << std::endl;
}

#endif /* STACK_H_ */
