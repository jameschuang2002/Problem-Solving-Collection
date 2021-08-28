/* Question Description 
* Given a string S of n characters
* Find a string T of n characters s.t. T is minimized in dictionary sorting
* You can perform the following actions: 
* Move a character from the start of S to the end of T
* Move a character from the end of S to the end of T 
* Conditions: 0 <= n <= 2000, All characters are capitalized 
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_CHARS 2000
#define TRUE 1
#define FALSE 0

int main(void){
	/* variable declaration and input */
	char str[MAX_CHARS + 1], ans[MAX_CHARS + 1];
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	strcpy(reverse, str);
	strrev(reverse);

	
	int front = TRUE;
	
	int startIndex = 0, endIndex = n-1, ansIndex = 0;
	while(startIndex <= endIndex){
		if(str[startIndex] < str[endIndex])
			ans[ansIndex++] = str[startIndex++];
		else if(str[startIndex] == str[endIndex]){
			int checkSingle = TRUE;
			for(int i = 0; i < endIndex - startIndex; i++){
				if(str[startIndex + i] < str[endIndex - i]){
					ans[ansIndex++] = str[startIndex++];
					checkSingle = FALSE;
					break;
				}
				else if(str[startIndex + i] > str[endIndex - i]){
					ans[ansIndex++] = str[endIndex--];
					checkSingle = FALSE;
					break;
				}
			}
			if(checkSingle == TRUE) ans[ansIndex++] = str[endIndex--]; 
	    }
		else
			ans[ansIndex++] = str[endIndex--];
	}
	printf("%s\n", ans);
	return 0; 
}






