//============================================================================
// Name        : DS_Assignment_3.cpp
// Author      : Ahmed
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

#define ARRAY_MAX_SIZE		100

#define ARRAY_RAND_MIN		3
#define ARRAY_RAND_MAX		10

#define PRINT_WIDTH			100
#define PRINT_CHAR			'='
#define PRINT_LINE()		cout << setfill(PRINT_CHAR) << setw(PRINT_WIDTH) << "" << endl

#define LINE_BY_LINE		0
#define INLINE				1
#define PRINT_ARRAY_OPTION	INLINE

enum class Error_t {
	NO_ERROR, INVALID_ARRAY_SIZE

};

bool sortA(int &a, int &b) {
	return a < b;
}

bool sortD(int &a, int &b) {
	return a > b;
}

class SortingAlg {
	public:
		//TODO: Add lambda function to determine sort direction
		static void insertionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
		static void bubbleSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
		static void selectionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
		static void mergeSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
	private:
		static void swapElements(int &firstElement, int &secondElement);
		static void merge(int *arr, const unsigned int &arrSize);
};

void SortingAlg::mergeSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {

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

void SortingAlg::insertionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {
	unsigned int i, j;
	for (i = 1; i <= arrSize - 2; i++) {
		for (j = i; j > 0; j--) {
			if (ptrFunction(arr[j], arr[j - 1])) {
				SortingAlg::swapElements(arr[j], arr[j - 1]);
			}
		}
	}
}

void SortingAlg::bubbleSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {

	bool isDone;

	unsigned int i, j;
	for (i = 0; i < arrSize - 1; i++) {

		isDone = true;

		for (j = 0; j < arrSize - i - 1; j++) {
			if (ptrFunction(arr[j + 1], arr[j])) {
				SortingAlg::swapElements(arr[j + 1], arr[j]);
				isDone = false;
			}
		}

		if (isDone == true) {
			break;
		}
	}

}

void SortingAlg::selectionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&)) {

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
			SortingAlg::swapElements(arr[pivotElementIndex], arr[i]);
		}

	}
}

void SortingAlg::swapElements(int &firstElement, int &secondElement) {
	int temp = firstElement;
	firstElement = secondElement;
	secondElement = temp;
}

class Array_IO {
	public:
		static Error_t inputArray(int *arr, const unsigned int &arrSize);
		static Error_t inputRandom(int *arr, const unsigned int &arrSize, const int &minElement, const int &maxElement);
		static void printArray(int *arr, const unsigned int &arrSize);

	private:
		static constexpr unsigned int arrayMaxSize = ARRAY_MAX_SIZE;
};

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
//		SortingAlg::bubbleSort(array, arraySize, sortA);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Bubble Sort D:" << endl;
//		Array_IO::printArray(array, arraySize);
//		SortingAlg::bubbleSort(array, arraySize, sortD);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Selection Sort A:" << endl;
//		Array_IO::printArray(array, arraySize);
//		SortingAlg::selectionSort(array, arraySize, sortA);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Selection Sort D:" << endl;
//		Array_IO::printArray(array, arraySize);
//		SortingAlg::selectionSort(array, arraySize, sortD);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Insertion Sort A:" << endl;
//		Array_IO::printArray(array, arraySize);
//		SortingAlg::insertionSort(array, arraySize, sortA);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Insertion Sort D:" << endl;
//		Array_IO::printArray(array, arraySize);
//		SortingAlg::insertionSort(array, arraySize, sortD);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}

	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
	if (currentErrorMessage == Error_t::NO_ERROR) {

		cout << "Merge Sort A:" << endl;
		Array_IO::printArray(array, arraySize);
		SortingAlg::mergeSort(array, arraySize, sortA);
		Array_IO::printArray(array, arraySize);
		PRINT_LINE();
	}

	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
	if (currentErrorMessage == Error_t::NO_ERROR) {

		cout << "Merge Sort D:" << endl;
		Array_IO::printArray(array, arraySize);
		SortingAlg::mergeSort(array, arraySize, sortD);
		Array_IO::printArray(array, arraySize);
		PRINT_LINE();
	}

	return 0;
}
