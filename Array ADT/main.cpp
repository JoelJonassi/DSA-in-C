
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


typedef struct _Array {
	int* data;
	int size;
	int length;
} Array;


/**
 * Function to display array.
 * 
 * \param arr
 */
void Display(Array arr) {
	for (int i = 0; i < arr.length; i++) {
		cout << arr.data[i] << "\n" ;
	}
}


/**
 * Function to append on ADT Array.
 * 
 * \param arr
 * \param value
 */
void Append(Array* arr, int value) {
	if (arr->length < arr->size)
		arr->data[arr->length++] = value;
}



/**
 * Insert value at index.
 * 
 * \param arr
 * \param index
 * \param value
 */
void Insert(Array* arr, int index, int value) {
	if (index >= 0 && index <= arr->length) {
		for (int i = arr->length; i > index; i--)
			arr->data[i] = arr->data[i - 1];
		arr->data[index] = value;
		arr->length++;
	}
}

/**
 * Delete index value.
 * 
 * \param arr
 * \param index
 * \return 
 */
int Delete(Array *arr, int index) {
	if (index >= 0 && index <= arr->length) {
		int deletedValue = arr->data[index];
		for (int i = index; i < (arr->length - 1); i++)
			arr->data[i] = arr->data[i + 1];
		arr->length--;
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
int LinearSearch(Array *arr, int key) {
	for (int i = 0; i < arr->length; i++) {
		if (key == arr->data[i])
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
int LinearSearchTransposition(Array *arr, int key){
	for (int i = 0; i < arr->length; i++) {
		if (key == arr->data[i]) {
			int temp = arr->data[i-1];
			arr->data[i - 1] = arr->data[i];
			arr->data[i] = temp;
			return i;
		}
	}
	return -1;
}

/**
 * Move to front at position zero.
 * 
 * \param arr
 * \param key
 * \return 
 */
int LinearSearchMovedAhead(Array* arr, int key) {
	for (int i = 0; i < arr->length; i++) {
		if (key == arr->data[i]) {
			int temp = arr->data[0];
			arr->data[0] = arr->data[i];
			arr->data[i] = temp;
			return i;
		}
	}
	return -1;
}

// For binary search condition:  Sorted array
/**
 * .
 * 
 * \param arr
 * \param low
 * \param high
 * \param key
 * \return 
 */
int BinarySearchIterative(Array *arr, int low, int high, int key) {
	int mid;
	while (low <= high ) {
		mid = (low + high) / 2;
		if (arr->data[mid] == key) 
			return mid;
		else if (arr->data[mid] < key) 
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return -1;
}

/**
 * .
 * 
 * \param arr
 * \param low
 * \param high
 * \param key
 * \return 
 */
int BinarySearchRecursive(Array* arr, int low, int high, int key) {
	static int mid;
	if (low <= high) {
		mid = (low + high) / 2;
		if (arr->data[mid] == key)
			return mid;
		else if (key > arr->data[mid])
			return BinarySearchRecursive(arr, mid + 1, high, key);
		else
			return BinarySearchRecursive(arr, low, mid - 1, key);
	}
	else
		return -1;
}


int main() {
	
	Array arr;
	arr.size = 8;
	arr.data = (int*)malloc(arr.size * sizeof(int));
	arr.length = 2;

	arr.data[0] = 1;
	arr.data[1] = 3;



	Append(&arr, 4);
	Insert(&arr, 3, 12);
	Insert(&arr, 4, 14);
	Display(arr);
	cout << "Binary Search: " << BinarySearchRecursive(&arr,0, arr.length, 14) << "\n";


	LinearSearch(&arr, 3);
	Display(arr);
	LinearSearchMovedAhead(&arr, 12);
	Display(arr);
	LinearSearchTransposition(&arr, 4);
	Display(arr);

	cout << "Deleted : " << Delete(&arr, 2) << "\n";

	Display(arr);


}
