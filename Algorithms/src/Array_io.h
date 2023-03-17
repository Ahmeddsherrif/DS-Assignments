/*
 * Array_io.h
 *
 *  Created on: Mar 17, 2023
 *      Author: Master
 */

#ifndef ARRAY_IO_H_
#define ARRAY_IO_H_


#define ARRAY_MAX_SIZE		100

#define PRINT_WIDTH			100
#define PRINT_CHAR			'='
#define PRINT_LINE()		cout << setfill(PRINT_CHAR) << setw(PRINT_WIDTH) << "" << endl

#define LINE_BY_LINE		0
#define INLINE				1
#define PRINT_ARRAY_OPTION	INLINE

enum class Error_t {
	NO_ERROR, INVALID_ARRAY_SIZE
};


class Array_IO {
	public:
		static Error_t inputArray(int *arr, const unsigned int &arrSize);
		static Error_t inputRandom(int *arr, const unsigned int &arrSize, const int &minElement, const int &maxElement);
		static void printArray(int *arr, const unsigned int &arrSize);

	private:
		static constexpr unsigned int arrayMaxSize = ARRAY_MAX_SIZE;
};


#endif /* ARRAY_IO_H_ */
