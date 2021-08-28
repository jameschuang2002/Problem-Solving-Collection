/* Question Description 
* We got a rod of length l and there are n ants on the rod at position[i]
* i: [0, n-1], ants moved at a speed of 1 unit / sec
* direction of ants are unknown, if ants collide, they turn to the opposite direction
* find the max and min time for all ants to fall 
*/

#include <stdio.h>
int findMax(int arr[], int l);
int main(void){
	int length, n;
	scanf("%d%d", &length, &n);
	int location[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &location[i]);
	int midpoint = length / 2;
	int minTime[n], maxTime[n];
	for(int i = 0; i < n; i++){
		int time;
		if(location[i] > midpoint){
			minTime[i] = length - location[i];
			maxTime[i] = location[i];
		}
		else{
			minTime[i] = location[i];
			maxTime[i] = length - location[i];
		} 
	}
	printf("minimum time: %d", findMax(minTime, n));
	printf("maximum tume: %d", findMax(maxTime, n));
} 
int findMax(int arr[], int l){
	int ma = 0;
	for(int i = 0; i < l; i++){
		if(arr[i] > ma) ma = arr[i];
	}
	return ma;
}

