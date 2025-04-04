// Lab 11 - 4/3/2025

#include "MergeSort.hpp"

#include <iostream>

int main(void)
{
	int unsortedArray[6] = {4, 73, 2, 6, 10, 23};
	int *sortedArray = mergeSort<int>(unsortedArray, 6);
	
	for (int i = 0; i < 6; i++) {
		std::cout << sortedArray[i] << std::endl;
	}
	return 0;
}