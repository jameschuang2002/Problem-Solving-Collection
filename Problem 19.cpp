#include <stdio.h>
#include <stdlib.h>

/* symbolic constants */ 
#define TRUE 1
#define FALSE 0
#define STARTYEAR 1901
#define ENDYEAR 2000
#define NUM_MONTHS 12
#define FEBRUARY 1
#define DAYS_IN_YEAR 365

/* function prototypes */
int checkLeapYear(int year);
 
int main(){
	
	/* variable declaration */
	int daysInMonths[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int totalDays = DAYS_IN_YEAR;
	int currentDay = DAYS_IN_YEAR;
	int sundayCount = 0;
	
	for(int i = STARTYEAR; i <= ENDYEAR; i++){
		
		/* checking leap year */
		if(checkLeapYear(i)){
			daysInMonths[FEBRUARY] = 29;
			totalDays += 1;
		}
		else 
			daysInMonths[FEBRUARY] = 28;
			 
		for(int j = 0; j < NUM_MONTHS; j++){
			if(++currentDay % 7 == 0)
				sundayCount++;
			for(int k = 1; k < daysInMonths[j]; k++)
				currentDay++;
		}
	}
	printf("%d", sundayCount);
}

int checkLeapYear(int year){
	
	int isLeapYear;
	
	if(year % 400 == 0)
		isLeapYear = TRUE;
	else if(year % 4 == 0 && year % 100 != 0)
		isLeapYear = TRUE;
	else 
		isLeapYear = FALSE;
	
	return isLeapYear; 
}
