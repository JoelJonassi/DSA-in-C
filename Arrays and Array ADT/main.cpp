#include <stdio.h>
#include <stdlib.h>

// Add({3])
// Convert index in array to address (Add(A[3] = Lo + i * w))
// Lo -> base address i-> index  w -> size of data type
// integer 2 bytes  float 4 bytes  double 8 bytes character 1 byte

// static versus dynamic array


int main() {

#pragma region ArraysRepresentations

	int A[3][4] = { {1, 2, 3, 4},{2, 4, 6, 8}, {1, 3, 5, 7} }; // created inside stack
	
	int* p; // created in stack

	p = new int[5]; // memory in heap C++ lang
	p = (int*)malloc(5 * sizeof(int)); // heap in C lang
	// be careful to release memory to avoid memory leak
	delete[]p; // C++ lang
	free(p); // C lang

	int* B[3];
	int** C;

	B[0] = (int*) malloc(4 * sizeof(int));
	B[1] = (int*)malloc(4 * sizeof(int));
	B[2] = (int*)malloc(3 * sizeof(int));
	
	C = (int**)malloc(3 * sizeof(int*));
	C[0] = (int*)malloc(4 * sizeof(int));
	C[1] = (int*)malloc(4 * sizeof(int));
	C[2] = (int*)malloc(4 * sizeof(int));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	// int A[3][4]
	//		m x n
	// Row Major Formula for 2D Arrays  -> Addr([i][j]) = Lo + [i * n + j] * w
	// Column Major Formula for 2D Arrays -> Addr([i][j]) = Lo +[j * m + i] * w 


	// A00	A01	A02
	// A10	A11	A12
	// A20	A21	A22
#pragma endregion

#pragma region ArrayADT

#pragma endregion

	return 0;
}
