#include <stdio.h>
#include <stdlib.h>

/* symbolic constants */
#define LENGTH 1000
#define NULL_CHAR 20
/* function prototypes */
void getFibonacci(int n);

int main(void){
	int firstNum[LENGTH], secondNum[LENGTH], answer[LENGTH];
	
	for(int i = 0; i < LENGTH; i++){
		firstNum[i] = NULL_CHAR;
		secondNum[i] = NULL_CHAR; 
		answer[i] = NULL_CHAR;
	}
	firstNum[LENGTH - 1] = 1;
	secondNum[LENGTH - 1] = 1;
	int count = 2;
	do {
		count++;
		/* addition at each level */
		for(int i = LENGTH - 1; firstNum[i] != NULL_CHAR || secondNum[i] != NULL_CHAR; i--){
			if(firstNum[i] == NULL_CHAR)
				answer[i] = secondNum[i];
			else if(secondNum[i] == NULL_CHAR)
				answer[i] = firstNum[i];
			else
				answer[i] = firstNum[i] + secondNum[i];
		}
		/* processing increase in number levels */
		for(int i = LENGTH - 1; answer[i] != NULL_CHAR && i > 0; i--){
			if(answer[i] >= 10){
				if(answer[i-1] == NULL_CHAR)
					answer[i-1] = answer[i] / 10;
				else 
					answer[i-1] += answer[i] / 10;
				answer[i] %= 10;	
			}
	 	}
		/* reinitialization */
		for(int i = 0; i < LENGTH; i++){
			firstNum[i] = secondNum[i];
			secondNum[i] = answer[i];
			answer[i] = NULL_CHAR;
		}		
	} while(secondNum[0] == NULL_CHAR);
	printf("%d\n", secondNum[0]);
	/* printing the results */
	printf("%d", count);
	return 0;
} 

