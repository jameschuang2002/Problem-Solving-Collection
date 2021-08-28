#include <stdio.h>
#define TRUE 1
#define FALSE 0 
int main(void){
	int flag;
	for(int i = 1; ; i++){
		flag = TRUE;
		for(int j = 1; j <= 20; j++){
			if(i % j != 0){
				flag = FALSE;
				break;
			}
		}
		if(flag == TRUE){
			printf("%d", i);
			break;
		}
	} 
	return 0;
} 
