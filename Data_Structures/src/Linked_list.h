/*
 * Linked_list.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Master
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

template<typename genericType>
struct Node {
		genericType data;
		Node *next;

		Node() :
				next { nullptr } {

			//data = genericType();
		}

		// TBC: Add Copy Ctor
};

template<typename genericType>
class Linked_list {
	private:
		Node<genericType> *head;
		Node<genericType> *tail;
		unsigned int capacity;
	protected:
		Linked_list();
		virtual ~Linked_list();

		void insert_front(Node<genericType>*);
		void insert_back(Node<genericType>*);

		Node<genericType>* get_head();
		Node<genericType>* get_tail();

		void remove_head();
		void remove_tail();

		bool isEmpty();
};

template<typename genericType>
Linked_list<genericType>::Linked_list() :
		head { nullptr }, tail { nullptr }, capacity { 0 } {
}

template<typename genericType>
void Linked_list<genericType>::insert_front(Node<genericType> *tempNodePtr) {

	// check if this is the first node in the list or not
	if (capacity == 0) {
		tempNodePtr->next = nullptr;
		this->tail = tempNodePtr;
	} else {
		tempNodePtr->next = this->head;
	}

	this->head = tempNodePtr;

	capacity++;
}

template<typename genericType>
void Linked_list<genericType>::insert_back(Node<genericType> *tempNodePtr) {

	tempNodePtr->next = nullptr;

	// check if this is the first node in the list or not
	if (capacity == 0) {
		(this->head) = tempNodePtr;
	} else {
		(this->tail)->next = tempNodePtr;
	}

	(this->tail) = tempNodePtr;

	capacity++;
}

template<typename genericType>
Node<genericType>* Linked_list<genericType>::get_head() {
	assert(this->capacity > 0);

	return head;
}

template<typename genericType>
Node<genericType>* Linked_list<genericType>::get_tail() {
	assert(this->capacity > 0);

	return tail;
}

template<typename genericType>
void Linked_list<genericType>::remove_head() {
	assert(this->capacity > 0);

	Node<genericType> *tempNodePtr = head;

	head = head->next;

	delete tempNodePtr;

	capacity--;

	if (capacity == 0) {
		assert(head == nullptr);
		this->tail = nullptr;
	}

}

template<typename genericType>
void Linked_list<genericType>::remove_tail() {
	assert(this->capacity > 0);

	Node<genericType> *previousNodePtr = nullptr;
	Node<genericType> *currentNodePtr = head;

	while (currentNodePtr->next != nullptr) {
		previousNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;
	}

	tail = previousNodePtr;

	delete currentNodePtr;
	currentNodePtr = nullptr;

	capacity--;

	if (capacity == 0) {
		assert(tail == nullptr);
		this->head = nullptr;
	}
}

template<typename genericType>
bool Linked_list<genericType>::isEmpty() {
	return (capacity == 0);
}

template<typename genericType>
Linked_list<genericType>::~Linked_list() {

	Node<genericType> *tempNodePtr = nullptr;
	Node<genericType> *currentNodePtr = nullptr;

	// Start at the address of head
	currentNodePtr = head;

	// keep hopping until you find the tail node
	while (currentNodePtr != nullptr) {
		tempNodePtr = currentNodePtr;
		currentNodePtr = currentNodePtr->next;

		delete tempNodePtr;
		tempNodePtr = nullptr;

	}
}

#endif /* LINKED_LIST_H_ */
