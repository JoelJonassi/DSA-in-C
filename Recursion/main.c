#include <stdio.h>
#include <stdlib.h>

int sum(n) {
	if (n == 0)
		return 0;
	return sum(n - 1) + 1;
}

int pow(int m, int n) {
	if (n == 0)
		return 1;
	return pow(m, n - 1) * m;
}

int pow_loop(int m, int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= m;
	}
	return result;
}

int pow_fast(int m, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) 
		return pow(m * m, n / 2);
	return pow(m*m, (n-1)/2) * m; //pow(m, n-1) * m
}

int factorial(int n) {
	if (n == 0)
		return 1;
	return factorial(n - 1) * n;
}

int fatorial_loop(int n) {
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
double e(int x, int n) {
	static double power = 1, factorial = 1;
	double result;
	if (n == 0)
		return 1;
	else {
		result = e(x, n - 1);
		power *= x;
		factorial *= n;	
		return result + power / factorial;;
	}
}

double e_fast(int x, int n) {
	static double store;
	if (n == 0)
		return store;
	store = 1 +  x * store / n;
	return e_fast(x, n - 1);	
}

double e_loop(int x, int n) {
	static double store = 1;
	for(; n > 0; n--){
		store = 1 + x * store / n;
	}
	return store;
}

int fib(int n) {
	if (n <= 1)
		return n; 
	return fib(n - 1) + fib(n-2);
}

int fib_it(int n) {
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
 * Fibonacci Memoization
 * Reduction of excessive calls.
 * 
 * \param n
 * \return 
 */
int fib_memoization(int n) {
	static int F[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	if (n <= 1) {
		F[n] = n;
		return n;
	}
	else {
		if (F[n - 2] == -1) {
			F[n - 2] = fib_memoization(n - 2);
		}
		if (F[n - 1] == -1) {
			F[n - 1] = fib_memoization(n - 1);
		}
		return F[n - 2] + F[n - 1];
	}

}

int main() {

	printf("Pow : %d\n", pow(2, 15));
	printf("Pow2 : %d\n", pow_fast(2, 15));
	printf("Pow Loop : %d\n", pow_loop(2, 15));
	printf("Factorial : %d\n", factorial(5));
	printf("Loop Factorial : %d\n", fatorial_loop(5));
	printf("Taylor Series : %f\n", e(1, 10));
	printf("Taylor Series loop : %f\n", e_loop(1, 10));
	printf("Taylor Series fast : %f\n", e_fast(1, 10));
	printf("Fibonacci Series : %d\n", fib(7));
	printf("Fibonacci Series Iterative: %d\n", fib_it(7));
	printf("Fibonacci Series Memoization: %d\n", fib_memoization(7));

	return 1;
}
