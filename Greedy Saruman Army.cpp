/* Question Description 
* There are n spots with position x0 to xn
* Each marked spot can cover a range of R
* Find the minimum spot that needs to be marked to cover all points
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std; 

#define MAX_PTS 1000
#define UNDEFINED -1
/* function prototypes */

int main(void){
	
	/* variable declaration + initialization + reading input */
	int n, range, pos[MAX_PTS], marked[MAX_PTS];
	scanf("%d%d", &n, &range);
	for(int i = 0; i < n; i++)
		scanf("%d", &pos[i]);
	for(int i = 0; i < MAX_PTS; i++)
		marked[i] = UNDEFINED;
	
	/* implementation */
	sort(pos, pos+n);
	int upper = pos[0] + range + 1, index = 0, count = 0;
	while(upper <= pos[n-1]){
		while(pos[index++] <= upper && index < n);
		marked[count] = pos[--index];
		upper = pos[--index] + 2 * range + 1;
		count++;
	}
	
	printf("%d", count);
	for(int i = 0; i < n; i++){
		if(marked[i] != UNDEFINED)
			printf("\n%d ", marked[i]); 
	}
	return 0;
} 
