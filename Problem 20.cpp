#include <stdio.h>
#include <stdlib.h>

#define TARGET 100
#define MAX_DIGITS 1000
#define NULLVAL -1

int main(void){
	
	int num[MAX_DIGITS];
	num[MAX_DIGITS - 1] = 1;
	
	for(int i = 0; i < MAX_DIGITS - 1; i++)
		num[i] = NULLVAL;
	
	for(int i = TARGET; i > 0; i--){
		
		for(int j = MAX_DIGITS - 1; num[j] != NULLVAL; j--)
			num[j] *= i;
		
		for(int j = MAX_DIGITS - 1; num[j] != NULLVAL; j--){
			if(num[j] >= 10){
				if(num[j - 1] == NULLVAL)
					num[j - 1]++;
				num[j - 1] += num[j] / 10;
				num[j] -= 10 * (num[j] / 10);
			}
		}	
	}
	
	printf("%d\n", num[0]);
	
	int sum = 0;
	for(int i = MAX_DIGITS - 1; num[i] != NULLVAL; i--)
		sum += num[i];
	printf("%d", sum);
	return 0;
}


