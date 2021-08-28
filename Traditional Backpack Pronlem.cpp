/* Question Description 
* with n items with value vi to vn, and weight wi to wn
* W is the total weight that can be carried
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std; 

#define NUM_ITEMS 100
#define NULLVAL -1
int solve(int index, int leftSpace);
int max(int a, int b);

int n, W; // number of items, total weight 
int w[NUM_ITEMS], v[NUM_ITEMS]; // weight of items, value of items 
/* dp shows the max value 
* choosing from items after the i'th item 
* with total weight < j 
*/ 
int dp[NUM_ITEMS + 1][NUM_ITEMS + 1]; 
int main(void){
	
	/* reading inputs */
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &w[i], &v[i]);
	}
	scanf("%d", &W);
	
	/* dp initialization */
	for(int i = 0; i < NUM_ITEMS + 1; i++){
		for(int j = 0; j < NUM_ITEMS + 1; j++)
			dp[i][j] = NULL_VAL;
	}
	
	/* if no weight remaining, no val */
	for(int i = 0; i < n; i++)
		dp[i][0] = 0;
		
	/* if no items remaining, no val */
	for(int i = 0; i < W + 1; i++)
		dp[n][i] = 0;
	
	/* implementation: starting from last item and slowly increasing 
	* if I cannot or do not take the ith item, maxVal is the same without the ith item dp[i+1][j]
	* if I take the item, add val, use the maxVal from previous item with weights decreased
	 
	*/
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < W + 1; j++){
			if(j < w[i])
				dp[i][j] = dp[i+1][j];
			else{
				dp[i][j] = max(dp[i+1][j-w[i]] + v[i], dp[i+1][j]);
			}
		}
	}
	printf("%d\n", dp[0][W]);
	return 0;
}
/* recursive solution with call solve(0, W) */
int solve(int index, int leftSpace){
	int maxVal;
	if(index == n) 
		maxVal = 0;
	else if(leftSpace < w[index])
		maxVal = solve(index + 1, leftSpace);
	else{
		maxVal = max(solve(index + 1, leftSpace - w[index]) + v[index], solve(index + 1, leftSpace));
	}
	return maxVal;
}
int max(int a, int b){
	if(a > b) return a;
	else return b;
}
