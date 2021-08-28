#include <stdio.h>
#include <stdlib.h>

/* symbolic constants */
#define LENGTH 5
#define MAXIMUM 1001
#define SPIRAL_DIAG 4
#define START_VAL 1
#define STEP 2 

/* function prototypes */

int main(void){
	int sum = START_VAL, step = STEP;
	for(int i = 1; i < MAXIMUM * MAXIMUM;){
		for(int j = 0; j < SPIRAL_DIAG; j++){
			i += step;
			sum += i;
		} 
		step += STEP;
	}
	printf("%d", sum);
	return 0;
}

