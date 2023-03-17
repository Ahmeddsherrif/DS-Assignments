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
	private:
		static void swapElements(int &firstElement, int &secondElement);
		static void merge(int *arr, const unsigned int &arrSize);
};


#endif /* SORTING_H_ */
