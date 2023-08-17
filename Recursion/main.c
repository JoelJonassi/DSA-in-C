#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * Sum of n numbers recursion.
 * 
 * \param 
 * \return 
 */
int SumRecursion(n) {
	if (n == 0)
		return 0;
	return SumRecursion(n - 1) + 1;
}

/**
 * .
 * 
 * \param num
 * \param i
 * \return 
 */
bool IsPrime(int num, int i)
{	
	if (num <= 1) return false;
	if (i > sqrt(num)) return true;
	if (num % i == 0) return false;
	return IsPrime(num, i + 1);
}

bool IsPrime2(int num, int i) {
	if (num <= 1) return false;
	if (i * i > num) return true;
	if (num % i == 0) return false;
	return IsPrime2(num, i + 1);
}


/**
 * Pow Recursion.
 * 
 * \param m - base
 * \param n - expoent
 * \return 
 */
int PowRecursion(int m, int n) {
	if (n == 0)
		return 1;
	return PowRecursion(m, n - 1) * m;
}

/**
 * Pow loop.
 * 
 * \param m
 * \param n
 * \return 
 */
int PowIterative(int m, int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= m;
	}
	return result;
}

/**
 * .
 * 
 * \param m
 * \param n
 * \return 
 */
int PowRecursionFaster(int m, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) 
		return PowRecursionFaster(m * m, n / 2);
	return PowRecursionFaster(m*m, (n-1)/2) * m; //pow(m, n-1) * m
}




/**
 * .
 * 
 * \param n
 * \return 
 */
int FactorialRecursive(int n) {
	if (n == 0)
		return 1;
	return FactorialRecursive(n - 1) * n;
}



/**
 * .
 * 
 * \param n
 * \return 
 */
int FactorialIterative(int n) {
	int result = 1;
	for (int i = n; i > 0; i--) {
		result *= i;
	}
	return result;
}

/**
 * taylor series
 * 
 * \param x
 * \param n
 * \return 
 */
double TaylorRecursion(int x, int n) {
	static double power = 1, factorial = 1;
	double result;
	if (n == 0)
		return 1;
	else {
		result = TaylorRecursion(x, n - 1);
		power *= x;
		factorial *= n;	
		return result + power / factorial;;
	}
}

/**
 * .
 * 
 * \param x
 * \param n
 * \return 
 */
double TaylorRecursionFaster(int x, int n) {
	static double store;
	if (n == 0)
		return store;
	store = 1 +  x * store / n;
	return TaylorRecursionFaster(x, n - 1);
}

/**
 * .
 * 
 * \param x
 * \param n
 * \return 
 */
double TaylorIterative(int x, int n) {
	static double store = 1;
	for(; n > 0; n--){
		store = 1 + x * store / n;
	}
	return store;
}

/**
 * .
 * 
 * \param n
 * \return 
 */
int FibonacciRecursion(int n) {
	if (n <= 1)
		return n; 
	return FibonacciRecursion(n - 1) + FibonacciRecursion(n-2);
}

/**
 * .
 * 
 * \param n
 * \return 
 */
int FibonacciIterative(int n) {
	int t0 = 0, t1 = 1, sum;
	if (n <= 1) return n;
	for (int i = 2; i <= n; i++) {
		sum = t0 + t1;
		t0 = t1;
		t1 = sum;
	}
	return sum;
}

/**
 * Reduction of excessive calls..
 * 
 * \param n
 * \return 
 */
int FibonacciMemoization(int n) {
	static F[6] = {-1,-1,-1,-1,-1,-1};
	if (n <= 1) {
		F[n] = n;
		return n;
	}
	else {
		if (F[n - 2] == -1)
			F[n - 2] = FibonacciMemoization(n - 2);
		if (F[n - 1] == -1)
			F[n - 1] = FibonacciMemoization(n - 1);
	}
	return F[n - 2] + F[n - 1];	
}

/**
 * .
 * 
 * \param n
 * \param r
 * \return 
 */
int NCR(int n, int r) {
	int F1, F2, F3;
	F1 = FibonacciRecursion(n);
	F2 = FibonacciRecursion(r);
	F3 = FibonacciRecursion(n - r);
	
	return F1 / (F2 * F3);
}

/**
 * nCr.
 * 
 * \param n
 * \param r
 * \return 
 */
int NCRRecursion(int n, int r) {
	if (  n == r || r == 0)
		return 1;
	return NCRRecursion(n - 1, r - 1) + NCRRecursion(n - 1, r);
}

/**
 * Function to return a amonstrong number
 * Need to check if the value passed per parameter is the same as returned.
 * 
 * \param number Number to check
 * \param n Count of digits in value
 * \return Returns number if is the same as passed per parameter is amonstrong
 */
int  AmonstrongRecursion(int number, int n) {
	if (number == 0)
		return 0;
	return AmonstrongRecursion(number / 10, n) + PowRecursionFaster(number % 10, n);
}

/**
 * Function to check if is amonstrong.
 * 
 * \param number Number to check
 * \param n Count digits of value
 * \return Return 1 if amonstrong other wise return false
 */
int IsAmonstrongIterative(int number, int n) {
	int preserveNumber = number;
	int amonstrong = 0;
	for ( ; ; ) {
		int remainder = number % 10, aux_remainder = 1;
		number = number / 10;
		for (int i = 0; i < n; i++) {
			aux_remainder *= remainder;
		}
		amonstrong += aux_remainder;
		if (remainder == 0)
			break;
	}
	return amonstrong == preserveNumber;
}


/**
 * Tower of Hanoi recursion.
 * 
 * \param n
 * \param A
 * \param B
 * \param C
 */
void TowerHanoi(int n, char A, char B, char C) {
	if (n > 0) {
		TowerHanoi(n - 1, A, C, B);
		printf("\tMove %c to %c\n", A, C);
		TowerHanoi(n - 1, B, A, C);
	}
}



int main() {


	printf("Is Prime: %s\n", IsPrime(13, 2) == 0 ? "False" : "True");
	printf("Is Prime: %s\n", IsPrime2(10, 2) == 0 ? "False" : "True");
	printf("Pow recursion: %d\n", PowRecursion(2, 15));
	printf("Pow recursion faster : %d\n", PowRecursionFaster(2, 15));
	printf("Pow iterative : %d\n", PowIterative(2, 15));
	printf("Factorial recursive: %d\n", FactorialRecursive(5));
	printf("Factorial iterative : %d\n", FactorialIterative(5));                                          
	printf("Taylor Series : %f\n", TaylorRecursion(1, 10));
	printf("Taylor Series iterative : %f\n", TaylorIterative(1, 10));
	printf("Taylor Series fast : %f\n", TaylorRecursionFaster(1, 10));
	printf("Fibonacci Series : %d\n", FibonacciRecursion(7));
	printf("Fibonacci Series Iterative: %d\n", FibonacciIterative(7));
	printf("Fibonacci Series Memoization: %d\n", FibonacciMemoization(7));
	printf("Combination Recursion: %d \n", NCRRecursion(5, 1));
	printf("Combination: %d\n", NCR(5, 1));
	printf("Amonstrong Recursion: %d\n", AmonstrongRecursion(153, 3));
	printf("Amonstrong Iterative: %s\n", IsAmonstrongIterative(153, 3) == 1? "Is amonstrong" : "Isn't amonstrong");
	TowerHanoi(3, 'A', 'B', 'C');
                      
	return 1;
}
