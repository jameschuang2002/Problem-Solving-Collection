#include <stdio.h>
#include <stdlib.h>

/* symbolic constants */
#define TRUE 1
#define FALSE 0
#define MULTIPLE 2
#define REPETITIONS 1000
#define MAX_DIGITS 500
#define NULLVAL -1

int main(void){
	
	int num[MAX_DIGITS];
	
	for(int i = 0; i < MAX_DIGITS; i++)
		num[i] = NULLVAL;
		
	num[MAX_DIGITS - 1] = 1;
	int currentIndex;
	
	for(int i = 0; i < REPETITIONS; i++){
		
		for(currentIndex = MAX_DIGITS - 1; num[currentIndex] != NULLVAL; currentIndex--)
			num[currentIndex] *= MULTIPLE;
			
		for(currentIndex = MAX_DIGITS - 1; num[currentIndex] != NULLVAL; currentIndex--){
			
			if(num[currentIndex] >= 10){
				
				if(num[currentIndex - 1] == NULLVAL)
					num[currentIndex - 1]++;
					
				num[currentIndex - 1] += num[currentIndex] / 10;
				num[currentIndex] -= 10 * (num[currentIndex] / 10);
			}
		}
	}
	
	int sum = 0;
	
	for(int i = MAX_DIGITS - 1; num[i] != NULLVAL; i--){
		sum += num[i];
	}
	
	printf("%d\n", num[0]);
	printf("%d", sum);
	return 0;
}
