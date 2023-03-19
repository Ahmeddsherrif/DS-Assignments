//============================================================================
// Name        : DS_Assignment_3.cpp
// Author      : Ahmed
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "main.h"

//
//void quick_sort(int *arr , int first , int last)
//{
//	int pivot , temp , k1 , k2 ;
//	if(first >= last)		return;
//	pivot = arr[first] ;
//	k1 = first + 1;
//	k2 = last ;
//	while(k1 < k2)
//	{
//		while((k1 < last) && (arr[k1] <= pivot))		k1++;
//		while((k2 > first) && (arr[k2] >= pivot))		k2--;
//		if(k1 < k2) { temp = arr[k1] ; arr[k1] = arr[k2] ; arr[k2] = temp ; }
//	}
//
//	arr[first] = arr[k2] ; arr[k2] = pivot ;
//	quick_sort( arr , first , k2-1 );
//	quick_sort( arr , k2+1 , last);
//}
//

int main() {

	unsigned int arraySize = 4;
	int array[ARRAY_MAX_SIZE];

	PRINT_LINE();

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

//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Merge Sort A:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::mergeSort(array, arraySize, Sorting::sortA);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}
//
//	currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Merge Sort D:" << endl;
//		Array_IO::printArray(array, arraySize);
//		Sorting::mergeSort(array, arraySize, Sorting::sortD);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}

//currentErrorMessage = Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);

//	currentErrorMessage = Error_t::NO_ERROR;
//
//
//	if (currentErrorMessage == Error_t::NO_ERROR) {
//
//		cout << "Quick Sort:" << endl;
//
//
//
//		Array_IO::printArray(array, arraySize);
//		//Sorting::quickSort(array, arraySize);
//		quick_sort(array, 0, arraySize -1);
//		Array_IO::printArray(array, arraySize);
//		PRINT_LINE();
//	}

//	Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);
//
//	cout << "Count Sort:" << endl;
//	Array_IO::printArray(array, arraySize);
//	Sorting::countSort(array, arraySize);
//	Array_IO::printArray(array, arraySize);
//	PRINT_LINE();

	Array_IO::inputRandom(array, arraySize, ARRAY_RAND_MIN, ARRAY_RAND_MAX);

	cout << "Radix Sort:" << endl;
	Array_IO::printArray(array, arraySize);
	Sorting::radixSort(array, arraySize);
	Array_IO::printArray(array, arraySize);
	PRINT_LINE();

	return 0;
}
