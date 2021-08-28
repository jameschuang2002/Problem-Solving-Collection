#include <stdio.h>
#include <stdlib.h>

/* symbolic constants */
#define TRUE 1
#define FALSE 0
#define MAX_DIVISORS 100
#define TARGET 10000

/* function prototypes */
int checkAmicable(int n);
void getDivisors(int n, int divisors[MAX_DIVISORS]); // exclusive
int sum(int divisors[MAX_DIVISORS]);

int main(void){
	
	
	int total = 0;
	for(int i = 1; i <= TARGET; i++){
		if(checkAmicable(i))
			total += i;
	}
	printf("total: %d\n", total);
		
	return 0;
}

int checkAmicable(int n){
	int divisors[MAX_DIVISORS] = {0};
	int isAmicable;
	
	getDivisors(n, divisors);
	int firstSum = sum(divisors);
	
	
	for(int i = 0; divisors[i] != 0; i++)
		divisors[i] = 0;

	getDivisors(firstSum, divisors);
	int secondSum = sum(divisors);

	if(secondSum == n && firstSum != n)
		isAmicable = TRUE;
	else 
		isAmicable = FALSE;

	return isAmicable;	
}

void getDivisors(int n, int divisors[MAX_DIVISORS]){
	int index = 1;
	divisors[0] = 1;
	for(int i = 2; n / i >= i; i++){
		if(n % i == 0){
			divisors[index] = i;
			index++;
			divisors[index] = n / i;
			index++;
		}
	}
}

int sum(int divisors[MAX_DIVISORS]){
	int total = 0;
	for(int i = 0; divisors[i] != 0; i++)
		total += divisors[i];
	return total;
}
