/* Question Description 
* A board of length L must be divided into N parts of L0 to Ln 
* The cost to cut length l is l (cut 8 into 5 + 3, cost 8)
* What is the minimum cost to achieve the goal 
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_LENGTHS 20000
using namespace std;

int main(void){
	
	/* variable declaration and input */
	int n, lengths[MAX_LENGTHS];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &lengths[i]);
	
	/* implementation */
	
}
