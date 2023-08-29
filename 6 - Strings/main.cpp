#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/**
 * Length of string.
 * 
 * \param str
 * \return 
 */
int len(char* str) {
	int i = 0;
	for (i = 0; str[i] != '\0'; i++) {}
	return i;
}

//
/*
* Function to change case of string
* ASCII -> American Standard Code for Information Interchange
* A -> 65	a -> 97		0 -> 48
* B -> 66	b -> 98		1 -> 49
* C -> 67	c -> 99		2 -> 50
* ...		...			...
* Z ->90	z -> 122	9 -> 57
* Special caracters
* Enter -> 10
* Space -> 3
* Esc -> 27
* 
* ASCII 0 - 127 bits measn 7 bits are suitable to store ASCII
* 2^7 = 128 bits
*/
char* ChangeCase(char* string) {
	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] >= 65 && string[i] <= 90) {
			string[i] += 32;
		}
		else if (string[i] >= 97 && string[i] <= 122) {
			string[i] -= 32;
		}
	}
	return string;
}

/**
 * Counting vowels and consonants.
 * string
 * return vcount and ccount per reference 
 * 
 * \return 
 */

void CountVowelsConsonants(char* str, int* vcount, int* ccount) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'A' || str[i] == 'a' || str[i] == 'E' || str[i] == 'e' ||
			str[i] == 'I' || str[i] == 'i' || str[i] == 'O' || str[i] == 'o' ||
			str[i] == 'U' || str[i] == 'u')
			*vcount += 1;
		else if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			*ccount += 1;
	}
}

/**
* Count Words, do not consider double spaces
 * String: JOEL Is A gOOD   Engineer
 *			   ^  ^ ^    ^^^		Words are spaces + 1
 * \param string
 * \return 
 */
int CountWords(char* string) {
	int wcount = 1;
	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] == ' ' && (string[i] != string[i-1])) {
			wcount += 1;
		}
	}
	return wcount;
}

/**
 * .
 * 
 * \param str
 * \return 
 */
char* ReverseString(char* str){
	int length = len(str);
	char *str2 = (char*) malloc(sizeof(char));
	
	for (int i = length - 1, j = 0; i >= 0; i--, j++) {
		str2[j] = str[i];
	}
	str2[length] = str[length];
	return str2;
}

/**
 * Reverse string without create another array of char
 * string: JOEL
 *	Swap:	L E O J
 *			1 2 2 1
 * \param str
 * \return 
 */
char* ReverseString2(char* str) {
	int i = 0, j = len(str) - 1;
	while (i < j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return str;
}

/**
 * .
 * 
 * \param str
 * \return 
 */
int IsPalindrom(char* str) {
	char* reverseString = ReverseString2(str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != reverseString[i])
			return 0;
	}
	return 1;
}

/**
 * Find duplicates in a string.
 * Mark as zero:			0	0
 * Elements: F	i	n	d	i	n	g	s
 * 				i	i		j	j
 * Where i found zero are duplicared elements	
 * \return 
 */
//char* DuplicatedInString(char* str){}

char* MinMax(char* str) {
	char max = str[0];
	char min = str[0];
	for (int i = 0; str[i] != '\0'; i++) {
		if (max < str[i])
			max = str[i];
		else if (min > str[i])
			min = str[i];
			
	}
	char str2[2];
	str[0] = min;
	str[1] = max;
	return str;
}

/**
 * Review this function 
 * Find duplicate using hash table for capital and lower case letters.
 * String: J	o	e	l	J	o	n	a	s	s	i
 *										97		S
 *			
 * low = 97 - 97 = 0
 * high = s - 97
 * \return 
 */
int* FindDuplicateInStringUsingHash(char* str) {
	int min = (int)MinMax(str)[0], max = (int)MinMax(str)[1];
	max -= min;
	min -= min;

	int* hash = (int*)malloc((max) * sizeof(int));
	memset(hash, -1, sizeof(hash));
	for (int i = 0; str[i] != '\0'; i++) {
		if(str[i] >= 65 && str[i] <= 90)
			hash[(int)str[i] - 65]++;
		else if(str[i] >= 97 && str[i] <= 122)
			hash[(int)str[i] - 97]++;
	}
	return (int*)hash;
}

/**
 * Bitwise operations
 *		   7		6		5		4		3		2		1		0
 * 1 Byte |	0	|	0	|	0	|	0	|	0	|	0	|	0	|	1	|.
 *			128		64		32		16		8		4		2		1 
 *			Left Shift 1 
 *			H = H << 1
 * 		   7		6		5		4		3		2		1		0
 * 1 Byte |	0	|	0	|	0	|	0	|	0	|	0	|	1	|	0	|.
 *			128		64		32		16		8		4		2		1 
 * 
 * ANDing operations
 * a = 10 -> 1010
 * b =  6 -> 0110
 *			 0010 == a & b == 2	
 *ORing
 * a = 10 -> 1010
 * b =  6 -> 0110
 *			 1110 == a | b == 14
 * 
 * Masking is to know if a bit is on or not
 * (Variable A)
 *			7		6		5		4		3		2		1		0
 * 1 Byte |	0	|	0	|	0	|	1	|	0	|	0	|	0	|	0	|.
 *			128		64		32		16		8		4		2		1 
 
 * (Variable B)
 *			7		6		5		4		3		2		1		0
 * 1 Byte |	0	|	0	|	0	|	0	|	0	|	0	|	0	|	1	|.
 *			128		64		32		16		8		4		2		1 
 *			A = 1
 *			A << 2
 *			A & B = 0
 *			A << 4
 *			A & B = 16
 * 
 * Merging 
 *			A = 1
 *			A << 1
 *			A | B = 18
 *			A << 2
 *			A | B = 20
 *			
 *			f	i	n	d	i	n	g	s
 * 
 * \return 
 */
int* FindDuplicateInStringMaskingMerging(char* str) {
	int strBits = 0, strCompareBits = 0, * arr = (int*) malloc(len(str) * sizeof(int));
	for (int i = 0; str[i] != '\0'; i++) {
		strCompareBits = 1;
		strCompareBits = strCompareBits << (str[i] - 97);

		if ((strCompareBits & strBits) > 0){
			arr[i] = str[i];
		}
		else {
			strBits = strBits | strCompareBits;
		}
	}
	return arr;
}

/**
 * Chek for Anagram
 * 1) Aproach
 * Anagram means if two strings uses same set of alphabets
 * Check if the have the same size first
 * Create a hash table to count if the alphabet are unique in arr1 and increment 1
 * Scan the entire hash table and decrement the elements found on arr2 
 * Scan again and check if the hash have -1, 1 means we have duplicated or we have elements on arr2 not on arr1
 *  1 means we have elements on arr1 and not on arr2 and 0 definetly are anagrams
 *			 100	101		99		105		109		97     108
 *  A	 = | d	|	e	|	c	|	i	|	m	|	a	|	l	|
 *			100-97
 * 
 *			109		101		100		105		99		97		108	 
 *  B	=  | m	|	e	|	d	|	i	|	c	|	a	|	l	|
 * 
 * first scan string A
 *	H = |  1 |   | 1 | 1 | 1 |   |   |   | 1 |  |   | 1 | 1 |   |   |   |   |   |   |   |   |   |   |   |   |   |
 *		  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
 *
 * Second scan string B
 *	H = |  0 |   | 0 | 0 | 0 |   |   |   | 0 |  |   | 0 | 0 |   |   |   |   |   |   |   |   |   |   |   |   |   |
 *		  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25
 * len = n +n = 2n = O(n)
 * n + n = 2n = O(n)
 * Its possible to use bits to check anagrams if the string haven´t repeated values.
 *  \return 
 */
int CheckAnagrams(char* str1, char* str2) {
	int hash[26] = {0};
	if (len(str1) != len(str2)) return 0;
	for (int i = 0; str1[i] != '\0'; i++) {
		hash[str1[i] - 97]++;
	}
	for (int i = 0; str2[i] != '\0'; i++) {
		hash[str2[i] - 97]--;
		if (hash[str2[i] - 97] < 0)
			return 0;
	}
	return 1;
}


/**
 * Permutaions of strings  3! or n!
 * ABC
 * ACB
 * BAC
 * BCA
 * CAB
 * CBA.
 * string: |	 A		 |		B		|		C		|		\0		|
 * index:		0				1				2			3
 *							* State space tree (Backtracking)
 *							* Brute force (find out all possible permutations)
 *							* Recursion to achive backtracking with backtracking with are perform bruteforce 
 *								   /|\
 *								  / | \
 *								 /  |  \ 
 *                              /   |   \
 *							   /    |    \
 *							  / 	| 	  \	
 *							 /		|	   \ 
 *							/    	|	    \
 *						   A		B		 C
 *						  / \       /\      / \
 *						 B   C	   A  C    B   A
 *						/	  \    |  |   /     \
 *					   C	   B   C  A  A       B
 *					   |	   |   |  |  |       |  
 *	answer at leaf:	  ABC     ACB BAC|BCA|CBA   CAB		
 * 
 * \return 
 */
void StringPermutation(char* str, int k) {
	static int A[10] = { 0 };
	static char result[10];
	if (str[k] == '\0') {
		result[k] = '\0';
		cout<< result<<endl;
	}
	else {
		for (int i = 0; str[i] != '\0'; i++) {
			if (A[i] == 0) {
				result[k] = str[i];
				A[i] = 1;
				StringPermutation(str, k + 1);
				A[i] = 0;
			}
		}
	}

}

void Swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void StringPermutation2(char* str, int low, int high) {
	if (low == high) {
		cout << str << endl;
	}
	else {
		for (int i = low; i < high; i++) {
			Swap(&str[i], &str[low]);
			StringPermutation2(str, low + 1, high);
			Swap(&str[i], &str[low]);
		}
	}
}


int main() {
	char perm[] = "ABC";
	//StringPermutation(perm, 0);
	StringPermutation2(perm, 0, 3);

	char str[] = "JOEL Is A gOOD Engineer";
	char str2[] = "ddaabbccdeff";
	char pali[15] = "mbbhhnaccc";
	int vcount = 0, ccount = 0;
	int* duplicates = FindDuplicateInStringMaskingMerging(pali);
	for (int i = 0; pali[i] != '\0'; i++) 
		if(duplicates[i] > 0)
			cout << (char)duplicates[i] << endl;
	char medical[] = "medicals";
	char decimal[] = "decimals";
	cout <<"Are anagrams? " << CheckAnagrams(medical, decimal) << endl;
	CountVowelsConsonants(str, &vcount, &ccount);
	cout << "Count words: " << CountWords(str) << endl;
	cout << "Count vowels: " << vcount << " Count consonants: " << ccount << endl;
	cout << ChangeCase(str) << endl;
	cout << ReverseString(str) << endl;
	cout << ReverseString2(str) << endl;
	cout << IsPalindrom(pali) << endl;
	int* a = FindDuplicateInStringUsingHash(str2);
	int max = (int)MinMax(str2)[1];
	int min = (int)MinMax(str2)[0];
	for (int i = 0; i < (max-min); i++) {
		if (a[i] >= 0)
			if (a[i] >= 0 && a[i] <= 25)
				printf("%c", i + 97);
			else if (a[i] >= 26 && a[i] <= 72)
				printf("%c\n", i + 72);
	}
}

