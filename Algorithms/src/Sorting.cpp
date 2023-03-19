/*
 * sorting_alg.cpp
 *
 *  Created on: Mar 17, 2023
 *      Author: Master
 */

#include <string.h>
#include <assert.h>
#include <stack>

using namespace std;

#include "Sorting.h"

void Sorting::radixSort(int *arr, const unsigned int &arrSize) {

	int maxArrayElement = arr[0];

	unsigned int arrayIndex;
	for (arrayIndex = 0; arrayIndex < arrSize; arrayIndex++) {
		if (arr[arrayIndex] > maxArrayElement) {
			maxArrayElement = arr[arrayIndex];
		}
	}

	unsigned int numberOfDigits = 1;
	while (maxArrayElement > 9) {
		numberOfDigits++;
		maxArrayElement /= 10;
	}

	// Create New Count Array with Size equal to 10
	int *countArray = nullptr;
	countArray = new int[10]();
	assert(countArray != nullptr);
	unsigned int countArrayIndex;

	// Create Temp Array
	int *tempArray = nullptr;
	tempArray = new int[arrSize]();
	assert(tempArray != nullptr);
	unsigned int tempArrayIndex;

	unsigned int tenFactor = 1;
	unsigned int digitIndex;
	for (digitIndex = 1; digitIndex <= numberOfDigits; digitIndex++, tenFactor *= 10) {

		// Fill Count Array
		int currentArrayElement;
		unsigned int arrayIndex;
		for (arrayIndex = 0; arrayIndex < arrSize; arrayIndex++) {
			currentArrayElement = arr[arrayIndex];
			countArrayIndex = (currentArrayElement % (10 * tenFactor)) / tenFactor;
			countArray[countArrayIndex]++;
		}

		// Make Count Array Hold the End index to the Temp Array + 1
		for (countArrayIndex = 1; countArrayIndex < 10; countArrayIndex++) {
			countArray[countArrayIndex] += countArray[countArrayIndex - 1];
		}

		// Fill Temp Array
		for (arrayIndex = arrSize-1; static_cast<int>(arrayIndex) >= 0; arrayIndex--) {
			currentArrayElement = arr[arrayIndex];

			countArrayIndex = (currentArrayElement % (10 * tenFactor)) / tenFactor;
			tempArrayIndex = --countArray[countArrayIndex];		// to subtract the + 1

			tempArray[tempArrayIndex] = arr[arrayIndex];
		}

		// Zero Count Array
		memset(countArray, 0, 10 * sizeof(int));

		// Fill in the original Array
		for (arrayIndex = 0; arrayIndex < arrSize; arrayIndex++) {
			arr[arrayIndex] = tempArray[arrayIndex];
		}

		// Zero Temp Array
		memset(tempArray, 0, arrSize * sizeof(int));
	}

	// Delete Count Array
	delete[] countArray;
	countArray = nullptr;

	// Delete Temp Array
	delete[] tempArray;
	tempArray = nullptr;
}

void Sorting::countSort(int *arr, const unsigned int &arrSize) {

	int minElement = arr[0];
	int maxElement = arr[0];

	//find min and max elements
	unsigned int arrayIndex;
	for (arrayIndex = 0; arrayIndex < arrSize; arrayIndex++) {
		if (arr[arrayIndex] > maxElement) {
			maxElement = arr[arrayIndex];
		}

		else if (arr[arrayIndex] < minElement) {
			minElement = arr[arrayIndex];
		}
	}

	countSort(arr, arrSize, minElement, maxElement);
}

void Sorting::countSort(int *arr, const unsigned int &arrSize, const unsigned int &minElement, const unsigned int &maxElement) {

	// Create New Count Array with Size equal to size of the element range
	const unsigned int arrayElementRange = maxElement - minElement + 1;
	int *countArray = nullptr;
	countArray = new int[arrayElementRange]();
	assert(countArray != nullptr);
	unsigned int countArrayIndex;

	// Fill in the Count Array
	int currentArrayElement;
	unsigned int arrayIndex;
	for (arrayIndex = 0; arrayIndex < arrSize; arrayIndex++) {
		currentArrayElement = arr[arrayIndex];
		countArrayIndex = currentArrayElement - minElement;
		countArray[countArrayIndex]++;
	}

	// Make Count Array Hold the End index to the Temp Array + 1
	for (countArrayIndex = 1; countArrayIndex < arrayElementRange; countArrayIndex++) {
		countArray[countArrayIndex] += countArray[countArrayIndex - 1];
	}

	// Create Temp Array
	int *tempArray = nullptr;
	tempArray = new int[arrSize]();
	assert(tempArray != nullptr);
	unsigned int tempArrayIndex;

	// map the Temp Array index with the arrayElement and the count array
	for (arrayIndex = arrSize - 1; static_cast<int>(arrayIndex) >= 0; arrayIndex--) {
		currentArrayElement = arr[arrayIndex];

		countArrayIndex = currentArrayElement - minElement;
		tempArrayIndex = --countArray[countArrayIndex];		// to subtract the + 1

		tempArray[tempArrayIndex] = arr[arrayIndex];
	}


	delete[] countArray;
	countArray = nullptr;

	// Fill in the original Array
	for (arrayIndex = 0; arrayIndex < arrSize; arrayIndex++) {
		arr[arrayIndex] = tempArray[arrayIndex];
	}

	delete[] tempArray;
	tempArray = nullptr;
}

void Sorting::quickSort(int *arr, const unsigned int &arrSize) {

	if (arrSize == 1) {
		return;
	}

//ASSUME THAT THE PIVOT IS THE FIRST ELEMENT
	int &pivot = arr[0];

	unsigned int startIndex = 1;
	unsigned int endIndex = arrSize - 1;

	while (startIndex < endIndex) {

		while (arr[startIndex] < pivot && startIndex < endIndex) {
			startIndex++;
		}

		while (arr[endIndex] >= pivot && startIndex < endIndex) {
			endIndex--;
		}

		if (startIndex < endIndex) {
			swapElements(arr[endIndex], arr[startIndex]);
		}
	}

	if ((arr[endIndex] >= pivot) == false) {
		swapElements(pivot, arr[endIndex]);
	}

	int *leftPartionArray = arr;
	int leftPartionArraySize = endIndex;

	int *rightPartionArray = arr + endIndex;
	int rightPartionArraySize = arrSize - endIndex;

	quickSort(leftPartionArray, leftPartionArraySize);
	quickSort(rightPartionArray, rightPartionArraySize);
}

void Sorting::mergeSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {

	if (arrSize == 1) {
		return;
	}

// Create the two arrays
	int *leftArray = nullptr;
	int *rightArray = nullptr;

	unsigned int mid = arrSize / 2;
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

	while (leftIndex < leftArraySize) {
		arr[arrayIndex] = leftArray[leftIndex];
		leftIndex++;
		arrayIndex++;
	}

	while (rightIndex < rightArraySize) {
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
