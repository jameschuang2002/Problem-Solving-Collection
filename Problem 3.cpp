#include <stdio.h>
#define TRUE 1
#define FALSE 0
int main(){
	
	long long int number = 600851475143;
	int isPrime = TRUE;
	long long int i;
	
	for(i = number; i > 1; i--){
		isPrime = TRUE;
		for(long long int j = 2; i / j > j; j++){
			if(i % j == 0){
				isPrime = FALSE;
				break;
			}
		}
		if(isPrime == TRUE && number % i == 0)
			break;
	}
	printf("%lld", i);
}
