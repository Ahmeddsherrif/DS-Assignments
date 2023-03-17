//============================================================================
// Name        : DS_Assignment_3.cpp
// Author      : Ahmed
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "main.h"




int main() {

	unsigned int arraySize = 10;

	PRINT_LINE();

	int array[ARRAY_MAX_SIZE];

	Error_t currentErrorMessage;

//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Bubble Sort A:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::bubbleSort(array, arraySize, Sorting::sortA);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Bubble Sort D:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::bubbleSort(array, arraySize, Sorting::sortD);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Selection Sort A:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::selectionSort(array, arraySize, Sorting::sortA);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Selection Sort D:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::selectionSort(array, arraySize, Sorting::sortD);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Insertion Sort A:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::insertionSort(array, arraySize, Sorting::sortA);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Insertion Sort D:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::insertionSort(array, arraySize, Sorting::sortD);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}

	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
	if (currentErrorMessage == Error_t::NO_ERROR) {

		cout << "Merge Sort A:" << endl;
		Array_IO::printArray(array, arraySize);
		Sorting::mergeSort(array, arraySize, Sorting::sortA);
		Array_IO::printArray(array, arraySize);
		PRINT_LINE();
	}

	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
	if (currentErrorMessage == Error_t::NO_ERROR) {

		cout << "Merge Sort D:" << endl;
		Array_IO::printArray(array, arraySize);
		Sorting::mergeSort(array, arraySize, Sorting::sortD);
		Array_IO::printArray(array, arraySize);
		PRINT_LINE();
	}

	return 0;
}
