
/*****************************************************************//**
 * \file   main.cpp
 * \brief
 *
 * \author Joel Jonassi
 * \date   August 2023
 *********************************************************************/

#include <stdlib.h>
#include <iostream>
#include <stdbool.h>

#include <math.h>

using namespace std;

template<class T>

class Array {

private:
	T *data;
	int size;
	int length;
	void Swap(int* x, int* y);

public:
	Array() {
		size = 10;
		length = 0;
		data = new T[size];
	}

	Array(T sz) {
		size = sz;
		length = 0;
		data = new T[size];
	}

	~Array() {
		delete[]data;
	}

	void Display();
	void Append(T value);
	void Insert(int index, T value);
	T Delete(int index);
	int LinearSearch(T key);
	int LinearSearchTransposition(T key);
	int LinearSearchMovedAhead(T key);
	int BinarySearchIterative(int low, int high, T key);
	int BinarySearchRecursive(int low, int high, T key);
	Array* IncreaseArraySize(int size);
	void ReverseArray();
	void ReverseArray2();
	void InsertSorted(T value);
	int IsSorted();
	void NegativeOnBegin();
	Array* InitializeArray(int length, int size);
	Array* MergeSorted(Array* arr2);
	Array* UnionUnsorted(Array* arr2);
	Array* UnionSorted(Array* arr2);
	Array* IntersectionSorted(Array* arr2);
	Array* IntersectionUnsorted(Array* arr2);
	Array* DifferenceSorted(Array* arr2);
	Array* DifferenceUnsorted(Array* arr2);
};



/**
 * Function to display array.
 *
 * \param arr
 */
template<class T>
void Array<T>::Display() {
	for (int i = 0; i < length; i++) {
		cout << data[i] << endl;
	}
}


/**
 * Function to append on ADT Array.
 *
 * \param arr
 * \param value
 */
template<class T>
void Array<T>::Append(T value) {
	if (length < size)
		data[length++] = value;
}



/**
 * Insert value at index.
 *
 * \param arr
 * \param index
 * \param value
 */
template<class T>
void Array<T>::Insert(int index, T value) {
	if (index >= 0 && index <= length) {
		for (int i = length; i > index; i--)
			data[i] = data[i - 1];
		data[index] = value;
		length++;
	}
}

/**
 * Delete index value.
 *
 * \param arr
 * \param index
 * \return
 */
template<class T>
T Array<T>::Delete(int index) {
	if (index >= 0 && index <= length) {
		int deletedValue = data[index];
		for (int i = index; i < (length - 1); i++)
			data[i] = data[i + 1];
		length--;
		return deletedValue;
	}
	return 0;
}

/**
 * Function to search element in a array.
 *
 * \param arr
 * \param key
 * \return
 */
template<class T>
int Array<T>::LinearSearch(T key) {
	for (int i = 0; i < length; i++) {
		if (key == data[i])
			return i;
	}
	return -1;
}

/**
 * 1 move near to front.
 *
 * \param arr
 * \param key
 * \return
 */
template<class T>
int Array<T>::LinearSearchTransposition( T key) {
	for (int i = 0; i < length; i++) {
		if (key == data[i]) {
			int temp = data[i - 1];
			data[i - 1] = data[i];
			data[i] = temp;
			return i;
		}
	}
	return -1;
}

/**
 * Move to front at position zero.
 * O(n)
 * \param arr
 * \param key
 * \return
 */
template<class T>
int Array<T>::LinearSearchMovedAhead(T key) {
	for (int i = 0; i < length; i++) {
		if (key == data[i]) {
			int temp = data[0];
			data[0] = data[i];
			data[i] = temp;
			return i;
		}
	}
	return -1;
}

// For binary search condition:  Sorted array
/**
 * O(log n)
 *
 * \param arr
 * \param low
 * \param high
 * \param key
 * \return
 */
template<class T>
int Array<T>::BinarySearchIterative(int low, int high, T key) {
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (data[mid] == key)
			return mid;
		else if (data[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

/**
 * O(log n)
 *
 * \param arr
 * \param low
 * \param high
 * \param key
 * \return
 */
template<class T>
int Array<T>::BinarySearchRecursive(int low, int high, T key) {
	static int mid;
	if (low <= high) {
		mid = (low + high) / 2;
		if (data[mid] == key)
			return mid;
		else if (key > data[mid])
			return BinarySearchRecursive(mid + 1, high, key);
		else
			return BinarySearchRecursive(low, mid - 1, key);
	}
	else
		return -1;
}

/**
 * Function to increase array length.
 *
 * \param arrA
 * \param size
 * \return
 */
template<class T>
Array<T> *Array<T>::IncreaseArraySize( int size) {
	Array *myArray = new Array(size);
	for (int i = 0; i < length; i++) {
		myArray->data[i] = data[i];
		myArray->length = length;
	}
	delete []data;
	return myArray;
}


/**
 * O(n).
 *
 * \param arr
 */
template<class T>
void Array<T>::ReverseArray() {
	int* B = (int*)malloc(size * sizeof(int));
	for (int i = length - 1, j = 0; i >= 0; i--, j++) {
		B[j] = data[i];
	}
	for (int i = 0; i < length; i++) {
		data[i] = B[i];
	}
}


/**
 * Function to swap 2 values.
 *
 * \param x
 * \param y
 */
template<class T>
void Array<T>::Swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


/**
 * Second aproach of reversing array
 *
 * \param arr
 */
template<class T>
void Array<T>::ReverseArray2() {
	for (int i = 0, j = length - 1; i <= j; i++, j--) {
		Swap(&data[i], &data[j]);
	}
}

/**
 * Function to insert value on a sorted array.
 * Starts from the end of array checking if the value to insert is greater than the last one.
 * \param arr
 * \param value
 */
template<class T>
void Array<T>::InsertSorted(T value) {
	int i = length - 1;
	while (data[i] > value) {
		data[i + 1] = data[i];
		i--;
	}
	data[i + 1] = value;
	length++;
}

/**
 * Function to check if the array is sorted.
 *
 * \param arr
 * \return
 */
template<class T>
int Array<T>::IsSorted() {
	for (int i = 0; i < length - 1; i++) {
		if (data[i] > data[i + 1])
			return 0;
	}
	return 1;
}

/**
 * Function to bring all negatives values on begin of array.
 *
 * \param arr
 */
template<class T>
void Array<T>::NegativeOnBegin() {
	int i = 0;
	int j = length - 1;
	while (i < j) {
		while (data[i] < 0) i++;
		while (data[j] >= 0) j--;
		if (i < j)
			Swap(&data[i], &data[j]);
	}
}

/**
 * Function to initiliaze array.
 *
 * \param size
 * \return
 */
template<class T>
Array<T>* Array<T>::InitializeArray(int len, int size) {
	Array* arr = new Array(length + len);
	arr->data = new int[size];
	arr->size = size;
	arr->length = length;
	return arr;
}

/**
 * Function to merge arrays.
 *
 * \param arr1
 * \param arr2
 * \return
 */
template<class T>
Array<T>* Array<T>::MergeSorted(Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(length + arr2->length, size + arr2->size);
	while (i < length && j < arr2->length) {
		if (data[i] < arr2->data[j])
			arr3->data[k++] = data[i++];
		else
			arr3->data[k++] = arr2->data[j++];
	}
	for (; i < length; i++) {
		arr3->data[k++] = data[i];
	}
	for (; j < arr2->length; j++) {
		arr3->data[k++] = arr2->data[j];
	}
	return arr3;
}


/**
 * .
 *
 * \param arr1
 * \param arr2
 * \return
 */
template<class T>
Array<T>* Array<T>::UnionUnsorted(Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	int same = 0;
	Array* arr3 = InitializeArray(length + arr2->length, size + arr2->size);
	for (i = 0; i < length; i++) {
		arr3->data[k++] = data[i];
	}
	for (i = 0; i < arr2->length; i++) {
		for (j = 0; j < arr3->length; j++) {
			if (arr2->data[i] == arr3->data[j]) {
				same = 0;
				break;
			}
			else {
				same = 1;
			}
		}
		if (same) {
			arr3->data[k++] = arr2->data[i];
			arr3->length = k;
		}
	}
	arr3->length = k;
	return arr3;
}

/**
 * Function to perform union of arrays on sorted list.
 *
 * \param arr1
 * \param arr2
 * \return
 */
template<class T>
Array<T>* Array<T>::UnionSorted(Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(length + arr2->length, size + arr2->size);
	while (i < length && j < arr2->length) {
		if (data[i] < arr2->data[j])
			arr3->data[k++] = data[i++];
		else if (data[i] > arr2->data[j]) {
			arr3->data[k++] = arr2->data[j++];
		}
		else {
			arr3->data[k++] = data[i++];
			j++;
		}
	}
	for (; i < length; i++) {
		arr3->data[k++] = data[i];
	}
	for (; j < arr2->length; j++) {
		arr3->data[k++] = arr2->data[j];
	}
	arr3->length = k;
	return arr3;
}


/**
 * .
 *
 * \param arr1
 * \param arr2
 * \return
 */
template<class T>
Array<T>* Array<T>::IntersectionSorted(Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(length + arr2->length, size + arr2->size);
	while (i < length && j < arr2->length) {
		if (data[i] < arr2->data[j])
			i++;
		else if (data[i] > arr2->data[j])
			j++;
		else {
			arr3->data[k++] = data[i++];
			j++;
		}
	}
	arr3->length = k;
	return arr3;
}


/**
 * .
 *
 * \param arr1
 * \param arr2
 * \return
 */
template<class T>
Array<T>* Array<T>::IntersectionUnsorted(Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(length + arr2->length, size + arr2->size);
	for (i = 0; i < length; i++) {
		for (j = 0; j < arr2->length; j++) {
			if (data[i] == arr2->data[j]) {
				arr3->data[k++] = data[i];
			}
		}
	}
	arr3->length = k;
	return arr3;
}

/**
 * .
 *
 * \param arr1
 * \param arr2
 * \return
 */
template<class T>
Array<T>* Array<T>::DifferenceSorted(Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(length + arr2->length, size + arr2->size);
	while (i < length && j < arr2->length) {
		if (data[i] < arr2->data[j])
			arr3->data[k++] = data[i++];
		else if (data[i] > arr2->data[j])
			j++;
		else {
			j++;
			i++;
		}
	}
	for (; i < length; i++) {
		arr3->data[k++] = data[i];
	}
	arr3->length = k;
	return arr3;
}


/**
 * .
 *
 * \param arr1
 * \param arr2
 * \return
 */
template<class T>
Array<T>* Array<T>::DifferenceUnsorted(Array* arr2) {
	int i, j, k, same;
	i = j = k = same = 0;
	Array* arr3 = InitializeArray(length + arr2->length, size + arr2->size);
	for (; i < length; i++) {
		for (j = 0; j < arr2->length; j++) {
			if (data[i] == arr2->data[j]) {
				same = 1;
				break;
			}
			else
				same = 0;
		}
		if (!same)
			arr3->data[k++] = data[i];
	}
	arr3->length = k;
	return arr3;
}

int main() {

	Array<int>* arr;
	Array<int>* arr2;
	Array<int>* arr3;
	Array<int>* arrNegat;

	arr= new Array<int>(10);
	arr2 = new Array<int>(10);

	arrNegat = new Array<int>(10);

	arrNegat->Append( -1);
	arrNegat->Append( 8);
	arrNegat->Append( -4);
	arrNegat->Append( 2);
	arrNegat->Append( -10);
			
	cout << "Negative numbers at begin of array"<< endl;
	arrNegat->NegativeOnBegin();
	arrNegat->Display();

	arr2->Append(1);
	arr2->Append(2);
	arr2->Append(4);
	arr2->Append(8);
	arr2->Append(10);

	arr->Append(1);
	arr->Append(2);
	arr->Append(3);


	cout << "Union Sorted" << endl;
	arr3 = arr2->DifferenceUnsorted(arr);
	arr3->Display();

	cout << "Merge Sorted" << endl;
	arr3 = arr->MergeSorted(arr2);
	arr3->Display();

	arr->IsSorted() == 1 ? std::cout << "Is sorted" << endl : cout << "Isn't sorted" << endl;

	cout << "Reverse array 1" << endl;
	arr->ReverseArray();
	arr->Display();
	cout << "Reverse array 2" << endl;
	arr->ReverseArray2();
	arr->Display();

	cout << "Increase array" << endl;
	arr = arr->IncreaseArraySize(20);

	arr->Display();

	arr->Insert(3, 12);
	arr->Insert(4, 14);
	arr->Display();
	//cout << "Binary Search: " << arr->BinarySearchRecursive(0, arr->length, 14) << "\n";

	arr->IsSorted() == 1 ? cout << "Is sorted" << endl : cout << "Isn't sorted" << endl;

	arr->LinearSearch(3);
	arr->Display();

	arr->InsertSorted(6);
	arr->Display();
	cout << "Linear Search modev ahead";
	arr->LinearSearchMovedAhead(12);
	arr->Display();
	cout << "Linear Search transposition";
	arr->LinearSearchTransposition(4);
	arr->Display();

	cout << "Deleted : " << arr->Delete(2) << endl;

	arr->Display();
}
