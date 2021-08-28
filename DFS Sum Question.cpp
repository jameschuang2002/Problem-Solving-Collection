/* Question Description 
* Given n numbers and a target value
* return true if the sum of some numbers in the list equals the target value 
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_NUMS 20
int target;
int numbers[MAX_NUMS];

bool dfs(int i, int sum, int n);
int main(void){
	int n;
	/* reading inputs */
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);
	scanf("%d", &target);
	/* implementation */
	if(dfs(0, 0, n) == true)
		printf("Yes");
	else
		printf("No");
}
bool dfs(int i, int sum, int n){
	if(i == n) return sum == target; // return if all numbers are decided
	else if(dfs(i+1, sum, n)) return true; // not using the current item and getting the right answer
	else if(dfs((i+1), sum + numbers[i], n)) return true; //using the current item, add the value 
}

