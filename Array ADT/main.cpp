
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
#include <stdio.h>

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
 * O(n)
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
 * O(log n)
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
 * O(log n)
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

/**
 * Function to increase array length.
 * 
 * \param arrA
 * \param size
 * \return 
 */
Array IncreaseArraySize(Array* arrA, int size) {
	Array myArray;
	myArray.data = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < arrA->length; i++) {
		myArray.data[i] = arrA->data[i];
		myArray.size = size;
		myArray.length = arrA->length;
	}
	free(arrA->data);
	return myArray;
}


/**
 * O(n).
 * 
 * \param arr
 */
void ReverseArray(Array* arr) {
	int *B = (int*)malloc(arr->size * sizeof(int));
	for (int i = arr->length-1, j = 0; i >= 0; i--, j++) {
		B[j] = arr->data[i];
	}
	for (int i = 0; i < arr->length; i++) {
		arr->data[i] = B[i];
	}
}


/**
 * Function to swap 2 values.
 * 
 * \param x
 * \param y
 */
void Swap(int* x, int* y) {
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
void ReverseArray2(Array* arr) {
	for (int i = 0, j = arr->length-1; i <= j; i++, j--) {
		Swap(&arr->data[i], &arr->data[j]);
	}
}

/**
 * Function to insert value on a sorted array.
 * Starts from the end of array checking if the value to insert is greater than the last one.
 * \param arr
 * \param value
 */
void InsertSorted(Array* arr, int value) {
	int i = arr->length - 1;
	while (arr->data[i] > value) {
		arr->data[i + 1] = arr->data[i];
		i--;
	}
	arr->data[i + 1] = value;
	arr->length++;
}

/**
 * Function to check if the array is sorted.
 * 
 * \param arr
 * \return 
 */
int IsSorted(Array* arr) {
	for (int i = 0; i < arr->length - 1; i++) {
		if (arr->data[i] > arr->data[i + 1])
			return 0;
	}
	return 1;
}

/**
 * Function to bring all negatives values on begin of array.
 * 
 * \param arr
 */
void NegativeOnBegin(Array *arr) {
	int i = 0;
	int j = arr->length - 1;
	while (i < j) {
		while (arr->data[i] < 0) i++;
		while (arr->data[j] >= 0) j--;
		if( i < j)
			Swap(&arr->data[i], &arr->data[j]);
	}
}

/**
 * Function to initiliaze array.
 * 
 * \param size
 * \return 
 */
Array* InitializeArray(int length, int size) {
	Array* arr = (Array*)malloc(sizeof(Array));
	arr->data = (int*)calloc(size, sizeof(int));
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
Array* MergeSorted(Array* arr1, Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(arr1->length + arr2->length,arr1->size + arr2->size);
	while (i < arr1->length && j < arr2->length) {
		if (arr1->data[i] < arr2->data[j])
			arr3->data[k++] = arr1->data[i++];
		else
			arr3->data[k++] = arr2->data[j++];
	}
	for (; i < arr1->length; i++) {
		arr3->data[k++] = arr1->data[i];
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
Array* UnionUnsorted(Array* arr1, Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	int same = 0;
	Array* arr3 = InitializeArray(arr1->length + arr2->length,arr1->size + arr2->size);
	for (i = 0; i < arr1->length; i++) {
		arr3->data[k++] = arr1->data[i];
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
Array* UnionSorted(Array* arr1, Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(arr1->length + arr2->length,arr1->size + arr2->size);
	while (i < arr1->length && j < arr2->length) {
		if (arr1->data[i] < arr2->data[j]) 
			arr3[k++] = arr1[i++];
		else if(arr1->data[i] > arr2->data[j]) {
			arr3->data[k++] = arr2->data[j++];
		}
		else {
			arr3->data[k++] = arr1->data[i++];
			j++;
		}
	}
	for (; i < arr1->length; i++) {
		arr3->data[k++] = arr1->data[i];
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
Array* IntersectionSorted(Array* arr1, Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(arr1->length + arr2->length, arr1->size + arr2->size);
	while (i < arr1->length && j < arr2->length) {
		if (arr1->data[i] < arr2->data[j]) 
			i++;
		else if (arr1->data[i] > arr2->data[j]) 
			j++;
		else {
			arr3->data[k++] = arr1->data[i++];
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
Array* IntersectionUnsorted(Array* arr1, Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(arr1->length + arr2->length, arr1->size + arr2->size);
	for (i = 0; i < arr1->length; i++) {
		for (j = 0; j < arr2->length; j++) {
			if (arr1->data[i] == arr2->data[j]) {
				arr3->data[k++] = arr1->data[i];
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
Array* DifferenceSorted(Array* arr1, Array* arr2) {
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = InitializeArray(arr1->length + arr2->length, arr1->size + arr2->size);
	while (i < arr1->length && j < arr2->length) {
		if (arr1->data[i] < arr2->data[j])
			arr3->data[k++] = arr1->data[i++];
		else if (arr1->data[i] > arr2->data[j])
			j++;
		else {
			j++;
			i++;
		}
	}
	for (; i < arr1->length; i++) {
		arr3->data[k++] = arr1->data[i];
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
Array* DifferenceUnsorted(Array* arr1, Array* arr2) {
	int i, j, k, same;
	i = j = k = same = 0;
	Array* arr3 = InitializeArray(arr1->length + arr2->length, arr1->size + arr2->size);
	for (; i < arr1->length; i++) {
		for (j = 0; j < arr2->length; j++) {
			if (arr1->data[i] == arr2->data[j]) {
				same = 1;
				break;
			}
			else
				same = 0;
		}
		if(!same)
			arr3->data[k++] = arr1->data[i];
	}
	arr3->length = k;
	return arr3;
}

/**
 * Enter per parrameter.
 * O(n^2)
 * \param arr
 * \return 
 */
int Max(Array* arr) {
	int max = arr->data[0];
	for (int i = 1; i < arr->length; i++) {
		if (max < arr->data[i]) {
			max = arr->data[i];
		}
	}
	return max;
}

/**
 * Find min in array.
 * 
 * \param arr
 * \return 
 */
int Min(Array* arr) {
	int min = arr->data[0];
	for (int i = 1; i < arr->length; i++) {
		if (min > arr->data[i]) {
			min = arr->data[i];
		}
	}
	return min;
}



//Find Missing, duplicates elements on array area
/**
 * Find single missing element in a sorted array in sequence 
 * elements:		1	2	4	5	6
 * index:			0	1	2	3	4
 * Sum of n numbers = n(n+1)/2 
 *						6(6+1)/2 = 21 - (1+2+4+5+6) = 3
 *						The missing element in array is 3
 * \param arr
 * \return Missing element
 */
int FindSingleMissingElement(Array *arr) {
	int sum = 0, n = Max(arr);
	for (int i = 0; i < arr->length; i++) {
		sum += arr->data[i];
	}
	n = n * (n + 1) / 2;
	return (n - sum) == 0 ? -1 : (n-sum);

}

/**
 * Auxiliar functions.
 * 
 * \param arr
 * \param max
 * \return 
 */
int SumWithoutMissing(Array* arr, int max) {

	if (max == 1)
		return max;
	return SumWithoutMissing(arr, max - 1) + max;
}

/**
 * Missing functions.
 * 
 * \param arr
 * \param length
 * \return 
 */
int SumWithMissing(Array* arr, int length) {
	if (length == 0)
		return arr->data[length];
	return SumWithMissing(arr, length - 1) + arr->data[length];
}

/**
 * In sequence and sorted
 * Per paramenter the array, the value to iterate the array.
 * elements:		1	2	4	5
 * index:			0	1	2	3
 * n * (n+1)/2 == (n-3) + (n-2) + (n-1)... + 2 + 1 is to know if the all elment exists
 * 
 *		All elements		    f(5) = 15
 *								/ \
 *							  f(4) + 5
 *							  / \
 *							f(3) + 4
 *							/ \
 *						  f(2) + 3
 *						  / \
 *					   f(1) + 2
 *	With missing elements length of array wil be the heigth of the three recursion:
 *								 								
 *							  f(5) = 12
 *							  / \
 *							f(4) + 5
 *							/ \
 *						  f(2) + 4
 *						  / \
 *					   f(1) + 2
 * 
 * \return 
 */
int FindSingleMissingElementRecursive(Array* arr, int max, int length) {

	return SumWithoutMissing(arr, max) - SumWithMissing(arr, length);
}

/**
 * Using Index find a missing element in array
 * elements:			1	2	3	4	6 .
 * index:				0	1	2	3	4
 *diff= elem - index:	1	1	1	1	2
 *								index + diff
 * Compare the element minus index and the result need to be the same across the array other wise we find the missing element				
 * \return 
 */
int FindSingleMissingElementUsingIndex(Array* arr) {
	int diff = arr->data[0] - 0, i;
	for (i = 0; i < arr->length; i++) {
		if (diff != arr->data[i] - i)
			return i + diff;
	}
	return -1;
}


/**
* diff = d
* index = i
 * Elements:		A	1	2		4				8	7	9	10.
 * index:				0	1		2				3	4	5	6
 *								^^		^			^
 *diff = elemnt - index	1	1		2				5
 *							  i+d=3		i+d = 5
 *										d < A[i] - i
 *			O(n) - We don't consider the inside loop is negligable				
 * \param arr
 * \return 
 */
Array* FindMultipleMissingElementsUsingIndex(Array* arr) {
	int diff = arr->data[0];
	Array* arr2 = InitializeArray(0, arr->size);
	for (int i = 0; i < arr->length; i++) {
		if (diff != arr->data[i] - i) {
			while (diff < arr->data[i] - i) {
				Append(arr2, diff + i);
				diff++;
			}
		}
	}
	return arr2;
}

/**
 * Create a new array with a length of max value found.
 * Mark with 1's all founded elements
 * O(n)
 * Is where filled by 0's starting from interval [low value, high value]
 * \param arr
 * \return 
 */
Array* FindMutipleMissingElementsUsingHash(Array* arr) {
	int low = Min(arr);
	int high = Max(arr);
	Array* arr2 = InitializeArray(high, high);
	for (int i = 0; i < arr->length; i++) {
		arr2->data[arr->data[i]]++;
	}
	return arr2;
}

/**
 *  Elements:		1	2	3	3	4	4	4	6	9	9.
 *					0	1	2	3	4	5	6	7	8	9
 * \param arr
 * \return 
 */
Array* FindDuplicateSorted(Array* arr) {
	Array* arr2 = InitializeArray(arr->length, arr->size);
	int j = 0;
	int lastDuplicate = Min(arr) - 1; // the first element on duplicate doesn´t exist on array
	for (int i = 0; i < arr->length; i++) {
		if (arr->data[i] == arr->data[i - 1] && lastDuplicate != arr->data[i]) {
			lastDuplicate = arr->data[i];
			arr2->data[j++] = arr->data[i];
		}
	}
	return arr2;
}

/**
 * To count duplicate I will need a O(n^2) to iterate the array.
 * Elements:		1	2	3	3	4	4	4	6	9	9.
 *					0	1	2	3	4	5	6	7	8	9
 * \param arr
 * \return 
 */
int CountDuplicate(Array* arr) {
	int j = 0, count = 1;
	for (int i = 0; i < arr->length; i++) {
		j = i + 1;
		while (arr->data[i] == arr->data[j]) {
			j++;
			count++;
		}
		i = j - 1;
	}
	return count;
}

/**
 * For Sorted and Unsorted array 
 * This Function use hash to find duplicate value on sorted array
 * All elements with value greater than 1 are duplicated
 * O(n)
 * 
 * \param arr
 * \return 
 */
Array* FindDuplicateSortedHash(Array* arr) {
	int low = Min(arr);
	int high = Max(arr);
	Array* hash = InitializeArray(high, high);
	for (int i = 0; i < arr->length; i++) {
		hash->data[arr->data[i]]++;
	}
	return hash;
}

/**
 * .
 * O(n^2)
 * \param arr
 * \return 
 */
Array* FindDuplicateUnsorted(Array* arr) {
	Array* arr2 = InitializeArray(arr->length, arr->size);
	for (int i = 0; i < (arr->length - 1); i++) {
		if (arr->data[i] != -1) {
			for (int j = 0; j < arr->length; j++) {
				if (arr->data[i] == arr->data[j] && j != i) {
					arr2->data[j] = arr->data[j];
					arr->data[j] = -1;
				}
			}
		}
	}
	return arr2;
}

/**
 * O(n^2).
 * Pair which sum equal k
 * \param arr
 */
void FindPairSumK(Array* arr, int k) {
	for (int i = 0; i < (arr->length -1) ; i++) {
		for (int j = i + 1; j < arr->length; j++) {
			if (arr->data[i] + arr->data[j] == k)
				printf("%d + %d = %d\n", arr->data[i], arr->data[j], k);
		}
	}
}

//Array* FindPairSumK(Array* arr, int k) {

///}




int Max1(int* arr, int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int Min1(int* arr, int length) {
	int min = arr[0];
	for (int i = 1; i < length; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

/**
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 * Target :      9
 *  Elements:   2   7   11    15
 *              0   1    2    3
 *      9 - 2 = 7  mark 8 on our hash~
		9 - 7 = 2
 *              0                   1
 *      0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int max = Max1(nums, numsSize), min = Min1(nums, numsSize), value1, value2, arr[2];
	int* hash = (int*)malloc(max * sizeof(int));
	memset(hash, -1, max * sizeof(int));

	for (int i = 0; i < numsSize; i++) {
		if (hash[nums[i]] == -1)
			hash[nums[i]] = i;
		if (hash[target - nums[i]] >= 0 && (nums[i] + (target - nums[i] == target))) {
			value1 = i;
			value2 = hash[target - nums[i]];
		}
	}
	free(hash);
	arr[0] = value1 < value2 ? value1 : value2;
	arr[1] = value1 < value2 ? value2 : value1;

	return arr;
}





/**
 * Sorted array
 * Find pair k sum 
 *  * Target :      9
 *  Elements:   2   7   11    15
 *              0   1    2    3
 * 
 * \param arr
 * \param original
 */
Array* twoSum2(Array* nums, int target) {
	int i = 0, j = nums->length - 1;
	Array *arr = InitializeArray(2, 2);
	while (i < j) {
		if ((nums->data[i] + nums->data[j]) < target)
			i++;
		else if ((nums->data[i] + nums->data[j]) > target) 
			j--;
		else {
			arr->data[0] = i < j ? i : j;
			arr->data[1] = j > i ? j : i;
			break;
		}
	}
	return arr;
}

int* FindMaxAndMinSingleScan(Array* arr) {
	int* minMax = (int*)malloc(2 * sizeof(int));
	int max = arr->data[0];
	int min = arr->data[0];

	for (int i = 0; i < arr->length; i++) {
		if (max < arr->data[i])
			max = arr->data[i];
		else if (min > arr->data[i])
			min = arr->data[i];
	}

	minMax[0] = min;
	minMax[1] = max;
	return minMax;
}

void DisplaySum(int* arr, int* original) {
	cout << "[" << arr[0] << "," << arr[1] << "] = " << original[arr[0]] + original[arr[1]] << endl;
}

int main() {
	int nums[] = { 3,2,4 }, ret,  bb[2];

	DisplaySum(twoSum(nums, 3, 6, &ret), nums);
	
	Array arrSort;
	Array* arrMissing, *arrMissing2, *arrDuplicate;
	arrSort.size = 20;
	arrSort.data = (int*)malloc(arrSort.size * sizeof(int));
	arrSort.length = 0;
	Append(&arrSort, 5);
	Append(&arrSort, 4);
	Append(&arrSort, 3);
	Append(&arrSort, 10);
	Array* a = twoSum2(&arrSort, 8);
	Display(*a);
	int *minMax = (int*)malloc(2 * sizeof(int));
	minMax = FindMaxAndMinSingleScan(&arrSort);
	cout << "Min: " << minMax[0] << " Max: " << minMax[1] << endl;
	
	
	FindPairSumK(&arrSort, 5);

	cout << "This is missing element recursive " << FindSingleMissingElementRecursive(&arrSort, Max(&arrSort), (arrSort.length - 1)) << endl;
	cout << "This missing element is:" << FindSingleMissingElement(&arrSort) << endl;
	cout << "Missing element using index: " << FindSingleMissingElementUsingIndex(&arrSort) << endl;
	cout << "Multiple missing elements\n";

	Append(&arrSort, 9);

	arrMissing = FindMultipleMissingElementsUsingIndex(&arrSort);
	Display(*arrMissing);

	arrMissing2 = FindMutipleMissingElementsUsingHash(&arrSort);
	cout << "Multiple missing elementsHash\n";
	Display(*arrMissing2);

	Append(&arrSort, 9);
	Append(&arrSort, 10);
	Append(&arrSort, 10);
	Append(&arrSort, 12);

	cout << "Find duplicate on array\n" << endl;

	arrDuplicate = FindDuplicateSorted(&arrSort);
	Display(*arrDuplicate);

	cout << "Count Duplicate: " << CountDuplicate(&arrSort) << endl;

	cout << "Find duplicate on array Hash\n" << endl;
	arrDuplicate = FindDuplicateSortedHash(&arrSort);
	Display(*arrDuplicate);

	cout << "Find duplicate on array Unsorted\n" << endl;
	arrDuplicate = FindDuplicateUnsorted(&arrSort);
	Display(*arrDuplicate);

	Array arr;
	Array arr2;
	Array *arr3;
	Array arrNegat;

	arr2.size = 5;
	arr2.data = (int*)malloc(arr2.size * sizeof(int));
	arr2.length = 0;

	arrNegat.size = 5;
	arrNegat.data = (int*)malloc(arrNegat.size * sizeof(int));
	arrNegat.length = 0;

	Append(&arrNegat, -1);
	Append(&arrNegat, 8);
	Append(&arrNegat, -4);
	Append(&arrNegat, 2);
	Append(&arrNegat, -10);

	cout << "Negative numbers at begin of array\n";
	NegativeOnBegin(&arrNegat);
	Display(arrNegat);

	Append(&arr2, 1);
	Append(&arr2, 2);
	Append(&arr2, 4); 
	Append(&arr2, 8);
	Append(&arr2, 10);

	arr.size = 3;
	arr.data = (int*)malloc(arr.size * sizeof(int));
	arr.length = 2;
	arr.data[0] = 1;
	arr.data[1] = 3;
	Append(&arr, 4);

	cout << "Union Sorted\n";
	arr3 = DifferenceUnsorted(&arr2, &arr);
	Display(*arr3);

	cout << "Merge Sorted\n";
	arr3 = MergeSorted(&arr, &arr2);
	Display(*arr3);

	IsSorted(&arr) == 1 ? std::cout << "Is sorted\n" : cout << "Isn't sorted\n";

	cout << "Reverse array 1\n";
	ReverseArray(&arr);
	Display(arr);
	cout << "Reverse array 2\n";
	ReverseArray2(&arr);
	Display(arr);

	cout << "Increase array\n";
	arr = IncreaseArraySize(&arr, 20);

	Display(arr);

	Insert(&arr, 3, 12);
	Insert(&arr, 4, 14);
	Display(arr);
	cout << "Binary Search: " << BinarySearchRecursive(&arr,0, arr.length, 14) << "\n";

	IsSorted(&arr) == 1 ? cout << "Is sorted\n" : cout << "Isn't sorted\n";

	LinearSearch(&arr, 3);
	Display(arr);

	InsertSorted(&arr, 6);
	Display(arr);
	cout << "Linear Search modev ahead\n";
	LinearSearchMovedAhead(&arr, 12);
	Display(arr);
	cout << "Linear Search transposition\n";
	LinearSearchTransposition(&arr, 4);
	Display(arr);

	cout << "Deleted : " << Delete(&arr, 2) << "\n";

	Display(arr);
}
