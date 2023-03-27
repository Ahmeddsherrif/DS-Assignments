/*
 * StackLL.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Master
 */

#ifndef STACKLL_H_
#define STACKLL_H_

template<typename genericType>
class StackLL: public Linked_list<genericType> {
	public:
		StackLL();
		~StackLL();

		void push(const genericType&);
		void pop();
		bool isEmpty();

		genericType top();
};

template<typename genericType>
StackLL<genericType>::StackLL() {
}

template<typename genericType>
StackLL<genericType>::~StackLL() {

}

template<typename genericType>
void StackLL<genericType>::push(const genericType &inputData) {
	// Create Temp Node on The Heap
	Node<genericType> *tempNode = nullptr;
	tempNode = new Node<genericType>;
	assert(tempNode != nullptr);

	// copy the data into the Node
	tempNode->data = inputData;

	Linked_list < genericType > ::insert_front(tempNode);
}

template<typename genericType>
void StackLL<genericType>::pop() {
	Linked_list < genericType > ::remove_head();
}

template<typename genericType>
genericType StackLL<genericType>::top() {
	// Create Temp Node on The Heap
	Node<genericType> *tempNode = nullptr;
	tempNode = new Node<genericType>;
	assert(tempNode != nullptr);

	tempNode = Linked_list < genericType > ::get_head();

	return tempNode->data;
}

template<typename genericType>
bool StackLL<genericType>::isEmpty() {
	return Linked_list < genericType > ::isEmpty();
}

#endif /* STACKLL_H_ */
