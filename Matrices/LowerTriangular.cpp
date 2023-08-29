#include <iostream>

using namespace std;

class LowerTriangular {
private:
	int* A;
	int n;

public: 
	LowerTriangular() {
		n = 2;
		A = new int[2 * (2 + 1) / 2];
	}

	LowerTriangular(int n) {
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}

	~LowerTriangular() {
		delete[]A;
	}

	void Set(int i, int j, int value);
	int Get(int i, int j);
	void Display();
	int GetDimension() { return n; }
};


void LowerTriangular::Set(int i, int j, int value) {
	if (i >= j)
		//A[i * (i - 1) / 2 + j - 1] = value; // Row major formula
		A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = value; // Column major formula
}

int LowerTriangular::Get(int i, int j) {
	if (i >= j)
		//return A[i * (i - 1 / 2 + j - 1)];
		return A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j];
	return 0;
}

void LowerTriangular::Display() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= j)
				//cout << A[i * (i - 1) / 2 + j - 1] << "\t";
				cout << A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << "\t";
			else
				cout << "0\t";
		}
		cout << endl;
	}
}

int main1() {

	int dimension = 5;
	LowerTriangular lm =  LowerTriangular(dimension);
	for (int i = 1; i <= lm.GetDimension(); i++) {
		for (int j = 1; j <= lm.GetDimension(); j++) {
			if(i >= j)
				lm.Set(i, j,2);
		}
	}

	lm.Display();

	return  0;
}
