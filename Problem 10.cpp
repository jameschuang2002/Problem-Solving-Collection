#include <stdio.h>
#define MAX 2000000
#define TRUE 1
#define FALSE 0
int main(void){
	long long int sum = 2;
	int flag;
	for(int i = 3; i < MAX; i++){
		flag = TRUE;
		for(int j = 2; j < i; j++){
			if(i / j < j)
				break;
			if(i % j == 0){
				flag = FALSE;
				break;
			}
		}
		if(flag == TRUE){
			long long int temp = (long long int)(i);
			sum += temp;
		}
			
	}
	printf("%lld", sum);
}
