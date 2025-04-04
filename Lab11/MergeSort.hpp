#pragma once

template <typename T>
T* mergeSort(T arr[], int size)
{
	int midpoint = size / 2;

	if (size == 1) {
		return arr;
	}
	else {
		int leftArrSize = size - (size / 2), rightArrSize = size / 2;
		T leftArr[leftArrSize], rightArr[rightArrSize], sortedLeftArr[leftArrSize], sortedRightArr[rightArrSize];

		for (int i = 0; i < size; i++) {
			if (i < midpoint) {
				leftArr[i] = arr[i];
			}
			else {
				rightArr[i - midpoint] = arr[i];
			}
		}

		sortedLeftArr = mergeSort<T>(leftArr, leftArrSize);
		sortedRightArr = mergeSort<T>(rightArr, rightArrSize);

		return merge<T>(sortedLeftArr, sortedRightArr, size);
	}
}

template <typename T>
T* merge(T leftArr[], T rightArr[], int size)
{
	T sortedArray[size];

	int leftArrIndex = 0, rightArrIndex = 0;
	for (int i = 0; i < size; i++) {
		if (rightArrIndex < size / 2 && leftArr[leftArrIndex] < rightArr[rightArrIndex]) {
			sortedArray[i] = leftArr[leftArrIndex++];
		}
		else {
			sortedArray[i] = rightArr[rightArrIndex++];
		}
	}

	return sortedArray;
}