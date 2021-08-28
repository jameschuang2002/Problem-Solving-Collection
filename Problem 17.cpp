#include <stdio.h>
/* symbolic constants */

/* function prototypes */
int numberToWords(int n);

int main(void){
	int n = numberToWords(101);
	printf("%d\n", n);
	
	int sum = 0;
	for(int i = 1; i <= 1000; i++){
		sum += numberToWords(i); 
	}
	printf("%d", sum);
	
}

int numberToWords(int n){
	int digits[4] = {0};
	int i = 0;
	while(n > 0){
		digits[3 - i] = n % 10;
		n /= 10;
		i++;
	}
	int totalCharacters = 0;
	
	if(digits[0] > 0)
		totalCharacters += 8; // thousand
		
	if(digits[1] > 0 && (digits[2] != 0 || digits[3] != 0))
		totalCharacters += 10; // hundred and (exclude space)
	else if(digits[1] > 0 && digits[2] == 0 && digits[3] == 0)
		totalCharacters += 7; // hundred
		
	if(digits[2] > 1){
		// twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety
		int tens[] = {6, 6, 5, 5, 5, 7, 6, 6};
		totalCharacters += tens[digits[2] - 2];
	}
	else if(digits[2] == 1 && digits[3] != 0){
		// eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen
		int teens[] = {6, 6, 8, 8, 7, 7, 9, 8, 8};
		totalCharacters += teens[digits[3] - 1];
	}
	
	else if(digits[2] == 1 && digits[3] != 0)
		totalCharacters += 3;
	// one, two, three, four, five, six, seven, eight, nine
	
	int ones[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
	
	for(int i = 0; i < 4; i++){
		if(i == 2 && digits[i] == 1)
			break;
		else if(i == 2)
			continue;
			
		if(digits[i] != 0)
			totalCharacters += ones[digits[i] - 1];
	}
	
	if(digits[2] == 1 && digits[3] == 0)
		totalCharacters += 3; 
		
	return totalCharacters;
}
