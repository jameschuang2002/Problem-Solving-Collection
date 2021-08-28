#include <stdio.h>
#define MAXIMUM 1000000
int main(void){
	long long int collatzNumber, value;
	int count;
	int longestChain = 0;
	long long int i;
	for(i = 1; i <= MAXIMUM; i++){
		collatzNumber = i;
		count = 1;
		while(collatzNumber != 1){
			if(collatzNumber % 2 == 0)
				collatzNumber /= 2;
			else
				collatzNumber = 3 * collatzNumber + 1;
			count++;
		}
		if(count > longestChain){
			longestChain = count;
			value = i;
		}
	}
	printf("%lld", value);
}
