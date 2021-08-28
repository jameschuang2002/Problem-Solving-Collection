#include <stdio.h>
#include <stdlib.h>

/* symbolic constants */
#define TRUE 1
#define FALSE 0
#define MAXIMUM 1000
#define MINIMUM -1000

/* function prototypes */
int checkPrime(int n);
int calculateQuadratic(int n, int a, int b);

int main(void){
	/* 
	* first loop controlling "a", i
	* second loop controlling "b", j
	* third loop controlling the number of consecutive integers of prime numbers, k
	*/
	int max = -1, indexA, indexB;
	for(int i = MINIMUM + 1; i < MAXIMUM; i++){
		for(int j = MINIMUM; j < MAXIMUM + 1; j++){
			int count;
			for(count = 0; checkPrime(calculateQuadratic(count, i, j)) == TRUE; count++);
			if(count > max){
				max = count;
				indexA = i;
				indexB = j;
			}
		}
	}
	printf("%d", indexA * indexB);
	return 0;
} 

int checkPrime(int n){
	int isPrime = TRUE;
	if(n <= 0)
		return FALSE;
	for(int i = 2; n / i >= i; i++){
		if(n % i == 0)
			isPrime = FALSE;
	}
	return isPrime;
}

int calculateQuadratic(int n, int a, int b){
	return n * n + a * n + b;
}
