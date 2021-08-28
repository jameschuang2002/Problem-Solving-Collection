#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* symbolic constants */
#define MAX_DIGITS 201
#define NULL_VAL 10001
#define MAX_NUM 100
#define MAX_DISTINCT 10001
#define FALSE 0
#define TRUE 1

/* function prototypes */
void reset(int num[MAX_DIGITS]);
void structureNumber(int num[MAX_DIGITS]);
void computePower(int base, int exponent, int num[MAX_DIGITS]);
void printNumber(int num[MAX_DIGITS]); // for testing purposes 
void saveNumber(int num[MAX_DIGITS], char str[MAX_DIGITS + 1]);

int main(void){
	
	/* variable declaration */
	int num[MAX_DIGITS]; // number
	char dataBase[MAX_DISTINCT][MAX_DIGITS + 1]; // stores all previous values 
	char str[MAX_DIGITS + 1]; // stores current value
	int numData = 0; 
	
	/* 
	* first loop goes through all possible bases 
	* second loop goes through all possible exponents 
	*/
	
	for(int base = 2; base < MAX_NUM + 1; base++){
		for(int exp = 2; exp < MAX_NUM + 1; exp++){
			reset(num);
			computePower(base, exp, num);
			saveNumber(num, str);
			if(numData == 0){
				strcpy(dataBase[0], str);
				numData++;
			}
			else{
				int existed = FALSE;
				for(int i = 0; i < numData && existed == FALSE; i++){
					if(strcmp(dataBase[i], str) == 0)
						existed = TRUE;
				} 
				if(existed == FALSE)
					strcpy(dataBase[numData++], str);
			}
		}
	}
	
	printf("------------------------\n");
	for(int i = 0; i < numData; i++){
		printf("%s\t%d\n", dataBase[i], i+1);
	}
	
	printf("------------------------\n");

	printf("Answer: %d", numData);
	
	return 0;
} 

/* reset all values to null value */
void reset(int num[MAX_DIGITS]){
	for(int i = 0; i < MAX_DIGITS; i++)
		num[i] = NULL_VAL;
}

/* structure the number to its standard form */
void structureNumber(int num[MAX_DIGITS]){
	for(int i = MAX_DIGITS - 1; i >= 0; i--){
		if(num[i] >= 10 && num[i] != NULL_VAL){
			if(num[i-1] == NULL_VAL)
				num[i-1] = num[i] / 10;
			else
				num[i-1] += num[i] / 10;
			num[i] %= 10;
		}
	}
}

/* compute powers */
void computePower(int base, int exponent, int num[MAX_DIGITS]){
	num[MAX_DIGITS - 1] = base;
	for(int i = 0; i < exponent - 1; i++){
		for(int j = 0; j < MAX_DIGITS; j++){
			if(num[j] != NULL_VAL)
				num[j] *= base;
		}
		structureNumber(num);
	}
}

/* print out the number */
void printNumber(int num[MAX_DIGITS]){
	for(int i = 0; i < MAX_DIGITS; i++){
		if(num[i] != NULL_VAL)
			printf("%d", num[i]);
	}
	printf("\n");
}

/* save the number into a string */
void saveNumber(int num[MAX_DIGITS], char str[MAX_DIGITS + 1]){
	str[0] = '\0';
	int stringIndex = 0;
	for(int i = 0; i < MAX_DIGITS; i++){
		if(num[i] != NULL_VAL)
			str[stringIndex++] = num[i] + '0';
	}
	str[stringIndex] = '\0';
}
