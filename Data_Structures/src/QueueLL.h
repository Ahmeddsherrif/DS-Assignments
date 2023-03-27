/*
 * QueueLL.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Master
 */

#ifndef QUEUELL_H_
#define QUEUELL_H_

template<typename genericType>
class QueueLL: public Linked_list<genericType> {
	public:
		QueueLL();
		~QueueLL();

		void push(const genericType&);
		void pop();
		bool isEmpty();

		genericType front();
		genericType back();
};

template<typename genericType>
QueueLL<genericType>::QueueLL()
{

}
template<typename genericType>
QueueLL<genericType>::~QueueLL() {

}

template<typename genericType>
void QueueLL<genericType>::push(const genericType &inputData) {

	// Create Temp Node on The Heap
	Node<genericType> *tempNode = nullptr;
	tempNode = new Node<genericType>;
	assert(tempNode != nullptr);

	// copy the data into the Node
	tempNode->data = inputData;

	Linked_list < genericType > ::insert_back(tempNode);

}

template<typename genericType>
void QueueLL<genericType>::pop() {

	Linked_list < genericType > ::remove_head();

}

template<typename genericType>
genericType QueueLL<genericType>::front() {
	// Create Temp Node on The Heap
	Node<genericType> *tempNode = nullptr;
	tempNode = new Node<genericType>;
	assert(tempNode != nullptr);


	tempNode = Linked_list<genericType>::get_head();

	return tempNode->data;
}

template<typename genericType>
genericType QueueLL<genericType>::back() {

	// Create Temp Node on The Heap
	Node<genericType> *tempNode = nullptr;
	tempNode = new Node<genericType>;
	assert(tempNode != nullptr);

	tempNode = Linked_list<genericType>::get_tail();

	return tempNode->data;
}

template<typename genericType>
bool QueueLL<genericType>::isEmpty() {
	return Linked_list<genericType>::isEmpty();
}

#endif /* QUEUELL_H_ */
