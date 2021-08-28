#include <stdio.h>
int main(void){
	
	long long int triangleNumber;
	long long int i, j;
	int count;
	for(i = 1; count < 500; i++){
		
		triangleNumber = 0;
		count = 0;
		
		for(j = 1; j <= i; j++)
			triangleNumber += j;
			
		for(j = 1; triangleNumber / j > j; j++){
			
			if(triangleNumber % j == 0 && triangleNumber / j != j)
				count += 2;
			else if(triangleNumber % j == 0)
				count++;
				
		}
	}
	printf("%lld", triangleNumber);
	return 0;
} 
