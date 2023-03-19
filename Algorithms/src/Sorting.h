/*
 * sorting_alg.h
 *
 *  Created on: Mar 17, 2023
 *      Author: Master
 */

#ifndef SORTING_H_
#define SORTING_H_



class Sorting {
	public:
		static bool sortA(int &a, int &b) {
			return a < b;
		}

		static bool sortD(int &a, int &b) {
			return a > b;
		}

		static void insertionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
		static void bubbleSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
		static void selectionSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
		static void mergeSort(int *arr, const unsigned int &arrSize, bool (*ptrFunction)(int&, int&));
		static void quickSort(int *arr, const unsigned int &arrSize);

		static void countSort(int *arr, const unsigned int &arrSize);
		static void countSort(int *arr, const unsigned int &arrSize, const unsigned int& minElement, const unsigned int& maxElement);

		static void radixSort(int *arr, const unsigned int &arrSize);
	private:
		static void swapElements(int &firstElement, int &secondElement);
};


#endif /* SORTING_H_ */
