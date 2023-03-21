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
			//TBC: add data intializer
		}
};

template<typename genericType>
class Linked_list {
	private:
		Node<genericType> *head;
		Node<genericType> *tail;
		unsigned int capacity;
	public:
		Linked_list();
		void insert_front(Node<genericType>&);
		void insert_back(Node<genericType>&);

		Node<genericType> get_head();
		Node<genericType> get_tail();

		void remove_head();
		void remove_tail();

		bool isEmpty();
};

template<typename genericType>
Linked_list<genericType>::Linked_list() :
		head { nullptr }, capacity { 0 } {

}

template<typename genericType>
void Linked_list<genericType>::insert_front(Node<genericType> &inputNode) {

	if (capacity == 0) {
		inputNode.next = nullptr;
		tail = &inputNode;
	} else {
		inputNode.next = head;
	}

	head = &inputNode;

	capacity++;
}

template<typename genericType>
void Linked_list<genericType>::insert_back(Node<genericType> &inputNode) {

	inputNode.next = nullptr;

	if (capacity == 0) {

		head = &inputNode;
	} else {
		tail->next = &inputNode;
	}

	tail = &inputNode;

	capacity++;
}

template<typename genericType>
Node<genericType> Linked_list<genericType>::get_head(){
	assert(this->capacity > 0);

	return *head;
}

template<typename genericType>
Node<genericType> Linked_list<genericType>::get_tail(){
	assert(this->capacity > 0);

	return *tail;
}


template<typename genericType>
void Linked_list<genericType>::remove_head(){
	assert(this->capacity > 0);

	//TBC
	head = head->next;

	capacity--;

}

template<typename genericType>
void Linked_list<genericType>::remove_tail(){
	assert(this->capacity > 0);

	//TBC

	capacity--;
}

template<typename genericType>
bool Linked_list<genericType>::isEmpty() {
	return (capacity == 0);
}

//Node<genericType> *tempNode;
//
//// Start at the address of head
//tempNode = &head;
//
//// keep hopping until you find the tail node
//while (tempNode->next != nullptr) {
//	tempNode = &(tempNode->next);
//}
//
//// make the current Tail Node point to the inputNode
//tempNode->next = &inputNode;
//
//// Make the input Node the tail node (points to null)
//inputNode.next = nullptr;

#endif /* LINKED_LIST_H_ */
