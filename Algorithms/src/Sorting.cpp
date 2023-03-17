/*
 * sorting_alg.cpp
 *
 *  Created on: Mar 17, 2023
 *      Author: Master
 */


#include "Sorting.h"


void Sorting::mergeSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {

	unsigned int mid = arrSize / 2;

	if (mid == 0) {
		return;
	}

	// Create the two arrays
	int *leftArray = nullptr;
	int *rightArray = nullptr;

	unsigned int leftArraySize = mid;
	unsigned int rightArraySize = arrSize - mid;

	leftArray = new int[leftArraySize];
	rightArray = new int[rightArraySize];

	// Assign Values to the two arrays
	unsigned int arrayIndex = 0;


	unsigned int leftIndex;
	for (leftIndex = 0; leftIndex < leftArraySize; leftIndex++) {
		leftArray[leftIndex] = arr[arrayIndex];
		arrayIndex++;
	}

	unsigned int rightIndex;
	for (rightIndex = 0; rightIndex < rightArraySize; rightIndex++) {
		rightArray[rightIndex] = arr[arrayIndex];
		arrayIndex++;
	}

	//recursive call to split the array even further
	mergeSort(leftArray, leftArraySize, ptrFunction);
	mergeSort(rightArray, rightArraySize, ptrFunction);

	arrayIndex = 0;
	leftIndex = 0;
	rightIndex = 0;


	while ((leftIndex < leftArraySize) && (rightIndex < rightArraySize)) {

		if (ptrFunction(leftArray[leftIndex], rightArray[rightIndex]) == true) {
			arr[arrayIndex] = leftArray[leftIndex];
			leftIndex++;
		}

		else {
			arr[arrayIndex] = rightArray[rightIndex];
			rightIndex++;
		}

		arrayIndex++;
	}

	while(leftIndex < leftArraySize){
		arr[arrayIndex] = leftArray[leftIndex];
		leftIndex++;
		arrayIndex++;
	}

	while(rightIndex < rightArraySize){
		arr[arrayIndex] = rightArray[rightIndex];
		rightIndex++;
		arrayIndex++;
	}

	if (leftArray != nullptr) {
		delete[] leftArray;
		leftArray = nullptr;
	}

	if (rightArray != nullptr) {
		delete[] rightArray;
		rightArray = nullptr;
	}

}

void Sorting::insertionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {
	unsigned int i, j;
	for (i = 1; i <= arrSize - 2; i++) {
		for (j = i; j > 0; j--) {
			if (ptrFunction(arr[j], arr[j - 1])) {
				Sorting::swapElements(arr[j], arr[j - 1]);
			}
		}
	}
}

void Sorting::bubbleSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {

	bool isDone;

	unsigned int i, j;
	for (i = 0; i < arrSize - 1; i++) {

		isDone = true;

		for (j = 0; j < arrSize - i - 1; j++) {
			if (ptrFunction(arr[j + 1], arr[j])) {
				Sorting::swapElements(arr[j + 1], arr[j]);
				isDone = false;
			}
		}

		if (isDone == true) {
			break;
		}
	}

}

void Sorting::selectionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {

	int pivotElement;

	unsigned int i, j, pivotElementIndex;
	for (i = 0; i < arrSize - 1; i++) {
		pivotElementIndex = i;
		pivotElement = arr[pivotElementIndex];

		for (j = i; j < arrSize; j++) {
			if (ptrFunction(arr[j], pivotElement)) {
				pivotElementIndex = j;
				pivotElement = arr[pivotElementIndex];

			}
		}

		if (pivotElementIndex != i) {
			Sorting::swapElements(arr[pivotElementIndex], arr[i]);
		}

	}
}

void Sorting::swapElements(int &firstElement, int &secondElement) {
	int temp = firstElement;
	firstElement = secondElement;
	secondElement = temp;
}
