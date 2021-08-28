#include <stdio.h>
#define NUMBER 100
int main(void){
	int sumSquares = 0, sum = 0;
	for(int i = 1; i <= NUMBER; i++){
		sumSquares += i * i;
		sum += i;
	} 
	int squareSum = sum * sum;
	int dif = squareSum - sumSquares;
	printf("%d\n-%7d = %d", squareSum, sumSquares, dif);
	return 0;
}
