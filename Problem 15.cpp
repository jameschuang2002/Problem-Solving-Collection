#include <stdio.h>
#define SIZE 21 // grid represent the lines that mark the border
int main(void){
	long long int grid[SIZE][SIZE] = {0};
	grid[0][0] = 1;
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			if(i == 0 || j == 0)
				grid[i][j] = 1;
			else
				grid[i][j] = grid[i-1][j] + grid[i][j-1];
		}
	}
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			printf("%lld ", grid[i][j]);
		}
		printf("\n");
	}
	printf("%lld", grid[SIZE-1][SIZE-1]);
}
