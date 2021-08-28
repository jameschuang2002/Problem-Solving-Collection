#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define TARGET 10001
int main(void){
	int count = 1;
	int flag;
	int i;
	int primeNumbers[10001] = {0};
	primeNumbers[0] = 2;
	
	for(i = 3; count < TARGET ;i++){
		flag = TRUE;
		for(int j = 0; primeNumbers[j] != 0; j++){
			if(i % primeNumbers[j] == 0){
				flag = FALSE;
				break;
			}
		}
		if(flag == TRUE){
			primeNumbers[count] = i;
			count++;
		}
	} 
	printf("%d", primeNumbers[10000]);
	return 0;
}
