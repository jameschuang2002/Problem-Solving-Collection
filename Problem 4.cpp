#include <stdio.h>

/* symbolic constants */
#define TRUE 1
#define FALSE 0
#define MAX_DIGITS 8
/* function prototypes */
int checkPalindrome(int n);
int strlen(char str[]);

int main(){
	int answer;
	for(int i = 100; i < 1000; i++){
		for(int j = 100; j < 1000; j++){
			if(checkPalindrome(i * j) == 1 && i * j > answer)
				answer = i * j;
		}
	}
	printf("%d", answer);
}

int checkPalindrome(int n){
	char back[MAX_DIGITS];
	int calcStart = n;
	int isPalindrome = TRUE;
	
	/* set the integer to charcater array */
	int i = 0;
	while(calcStart > 0){
		back[i] = calcStart % 10 + '0';
		calcStart /= 10;
		i++;
	}
	/* check palindrome or not */
	int l = strlen(back);
	for(int i = 0; i < l/2; i++){
		if(back[i] != back[l-i-1])
			isPalindrome = FALSE;
	}
	return isPalindrome;
}

int strlen(char str[]){
	int i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}
