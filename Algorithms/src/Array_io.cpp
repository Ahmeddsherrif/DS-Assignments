/*
 * Array_io.cpp
 *
 *  Created on: Mar 17, 2023
 *      Author: Master
 */

#include <iostream>

using namespace std;

#include "Array_io.h"


Error_t Array_IO::inputArray(int *arr, const unsigned int &arrSize) {

	Error_t currentErrorMessage = Error_t::NO_ERROR;

	if (currentErrorMessage == Error_t::NO_ERROR) {
		if (arrSize > Array_IO::arrayMaxSize) {
			currentErrorMessage = Error_t::INVALID_ARRAY_SIZE;
		}
	}

	if (currentErrorMessage == Error_t::NO_ERROR) {
		int tempInput;
		unsigned int currentIndex;
		for (currentIndex = 0; currentIndex < arrSize; currentIndex++) {
			cout << "Array[" << currentIndex << "] = ";
			cin >> tempInput;

			//TODO: Error check on tempInput

			arr[currentIndex] = tempInput;
		}
	}

	return currentErrorMessage;
}

Error_t Array_IO::inputRandom(int *arr, const unsigned int &arrSize, const int &minElement, const int &maxElement) {

	Error_t currentErrorMessage = Error_t::NO_ERROR;

	srand(RAND_SEED);

	if (currentErrorMessage == Error_t::NO_ERROR) {
		if (arrSize > Array_IO::arrayMaxSize) {
			currentErrorMessage = Error_t::INVALID_ARRAY_SIZE;
		}
	}

	if (currentErrorMessage == Error_t::NO_ERROR) {
		int tempInput;
		unsigned int currentIndex;
		for (currentIndex = 0; currentIndex < arrSize; currentIndex++) {
			tempInput = minElement + rand() % (maxElement - minElement);
			arr[currentIndex] = tempInput;
		}
	}

	return currentErrorMessage;
}

void Array_IO::printArray(int *arr, const unsigned int &arrSize) {
	unsigned int currentIndex;
	for (currentIndex = 0; currentIndex < arrSize; currentIndex++) {

#if PRINT_ARRAY_OPTION == LINE_BY_LINE
		cout << "Array[" << currentIndex << "] = " << arr[currentIndex] << endl;

#elif PRINT_ARRAY_OPTION == INLINE
		cout << arr[currentIndex] << " \t";
#endif

}

#if PRINT_ARRAY_OPTION == INLINE
	cout << endl;
#endif

}
