#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <iostream>
using namespace std;

typedef struct _element {
	int rowi;
	int columnj;
	int value;
} Element;


typedef struct _sparseMatrix {
	int mRows;
	int nColumns;
	int nonZeroElements;
	struct _element* element;
} SparseMatrix;

SparseMatrix Create(int mRows, int nColumns, int nonZeroElements) {
	SparseMatrix sparse;
	sparse.mRows = mRows;
	sparse.nColumns = nColumns;
	sparse.nonZeroElements = nonZeroElements;
	sparse.element = (Element*)malloc(sparse.nonZeroElements * sizeof(Element));
	return sparse;
}

void FillSparseMatrix(SparseMatrix* sparse) {
	for (int i = 0; i < sparse->mRows; i++) {
		for (int j = 0; j < sparse->nColumns; j++) {
			sparse->element[i].rowi = i;
			sparse->element[i].columnj = j;
			sparse->element[i].value = 2;
		}
	}
}

void FillSparseMatrixManual(SparseMatrix* sparse) {
	cout << "Enter Sparse Matrix" << endl;
	cout << "row col value" << endl;
	for (int i = 0; i < sparse->nonZeroElements; i++) {
		scanf_s("%d%d%d", &sparse->element[i].rowi, &sparse->element[i].columnj, &sparse->element[i].value);
	}
}

void Display(SparseMatrix sparse) {
	int k = 0;
	for (int i = 0; i < sparse.mRows; i++) {
		for (int j = 0; j < sparse.nColumns; j++) {
			if (i == sparse.element[k].rowi && j == sparse.element[k].columnj)
				cout << sparse.element[k++].value << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
		
}



void AdditionProcess(SparseMatrix* s1, SparseMatrix* s2, SparseMatrix* sum) {
	int i, j, k;
	i = j = k = 0;
	while (i < s1->nonZeroElements && j < s2->nonZeroElements) {

		if (s1->element[i].rowi < s2->element[j].rowi) {
			sum->element[k++] = s1->element[i++];
		}
		else if (s1->element[i].rowi > s2->element[j].rowi) {
			sum->element[k++] = s2->element[j++];
		}
		else {
			if (s1->element[i].columnj < s2->element[j].columnj) {
				sum->element[k++] = s1->element[i++];
			}

			else if (s1->element->columnj > s2->element[j].columnj) {
				sum->element[k++] = s2->element[j++];
			}
			else {
				sum->element[k] = s1->element[i++];
				sum->element[k++].value += s2->element[j++].value;
			}
		}
	}
	for (; i < s1->nonZeroElements; i++) sum->element[k++] = s1->element[i];
	for (; j < s2->nonZeroElements; j++) sum->element[k++] = s2->element[j];
	sum->nonZeroElements = k;
}




SparseMatrix* Addition(SparseMatrix* s1, SparseMatrix* s2) {
	if (s1->mRows != s2->mRows || s2->nColumns != s1->nColumns)
		return NULL;
	SparseMatrix* sum = (SparseMatrix*)malloc(sizeof(SparseMatrix));
	assert(sum);
	sum->mRows = s1->mRows;
	sum->nColumns = s1->nColumns;
	sum->element = (Element*)malloc((s1->nonZeroElements + s2->nonZeroElements) * sizeof(Element));
	AdditionProcess(s1, s2, sum);
	return sum;
}


int main() {
	cout <<"Soma :" << Sum(2) << endl;
	SparseMatrix sparse1, sparse2, *sum;
	srand(time(NULL));
	sparse1 = Create(5, 5, 2);
	sparse2 = Create(5, 5, 2);
	cout << "One" << endl;
	FillSparseMatrixManual(&sparse1);
	FillSparseMatrixManual(&sparse2);


	Display(sparse1);

	cout << "Two" << endl;
	Display(sparse2);

	sum = Addition(&sparse1, &sparse2);
	cout << "Sum" << endl;
	Display(*sum);

	return 0;
}
