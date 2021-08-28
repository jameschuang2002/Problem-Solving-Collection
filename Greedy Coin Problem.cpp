/* Question Description
* You need to pay A dollars with the least number of coins 
* coins have the followings: 500, 100, 50, 10, 5, 1
* return the least number of coins required
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_COINS 6

int min(int a, int b);
int main(void){
	int dollars;
	scanf("%d", &dollars);
	int coins[] = {500, 100, 50, 10, 5, 1};
	int avaCoins[NUM_COINS];
	for(int i = 0; i < NUM_COINS; i++)
		scanf("%d", &avaCoins[i]);
	int count = 0;
	 // int coinIndex = 0; for the worse solution 
	
	/* better solution */
	for(int i = 0; i < NUM_COINS; i++){
		int used = min(dollars / coins[i], avaCoins[i]);
		dollars -= used * coins[i];
		count += used;
	}
	
	/* initial solution  
	do{
		if(dollars - coins[coinIndex] >= 0 && avaCoins[coinIndex] > 0){
			dollars -= coins[coinIndex];
			avaCoins[coinIndex]--;
			count++;
		}
		else
			coinIndex++;
	}while(dollars > 0);
	*/
	printf("%d", count);
} 

int min(int a, int b){
	if(a < b) return a;
	else return b;
}
