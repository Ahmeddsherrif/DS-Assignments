/*
 * Queue.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Master
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template<typename genericType>
class Queue {
	private:
		genericType *frontPtr;
		genericType *backPtr;

		genericType *buffer;

		unsigned int size;
		unsigned int capacity;

	public:
		Queue(const unsigned int &);
		~Queue();

		void push(const genericType &);
		void pop();
		bool isEmpty();

		genericType front();
		genericType back();
};

template<typename genericType>
Queue<genericType>::Queue(const unsigned int &size) :
		frontPtr { nullptr }, backPtr { nullptr }, buffer { nullptr }, size { size }, capacity { 0 } {

	this->buffer = new genericType[size]();

	assert(this->buffer != nullptr);

	this->frontPtr = &(this->buffer)[0];
	this->backPtr = &(this->buffer)[0] - 1;
}

template<typename genericType>
Queue<genericType>::~Queue() {

	assert((this->buffer) != nullptr);

	delete[] (this->buffer);
	(this->buffer) = nullptr;
}

template<typename genericType>
void Queue<genericType>::push(const genericType &s) {

	// is there a space in the queue or not?
	assert((this->capacity) < (this->size));

	(this->backPtr)++;		//10 elements   0-9
	if ((this->backPtr) >= &(this->buffer)[0] + size) {
		(this->backPtr) -= (this->size);
	}

	*(this->backPtr) = s;

	(this->capacity++);
}

template<typename genericType>
void Queue<genericType>::pop() {
	// is there elements in the queue or not?
	assert(capacity > 0);

	//cleared the memory
	*frontPtr = genericType();

	capacity--;

	frontPtr++;
	if (frontPtr >= &buffer[0] + size) {
		frontPtr -= size;
	}

}

template<typename genericType>
genericType Queue<genericType>::front() {
	assert(capacity > 0);
	return *frontPtr;
}

template<typename genericType>
genericType Queue<genericType>::back() {
	assert(capacity > 0);
	return *backPtr;
}

template<typename genericType>
bool Queue<genericType>::isEmpty() {
	return (capacity == 0);
}

#endif /* QUEUE_H_ */
