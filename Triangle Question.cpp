/* Question Description 
* Given n strings and form the largest triangle 
* if no triangles could be formed, return 0
*/

#include <stdio.h>
#include <stdlib.h>
int maxi(int a, int b);
int main(void){
	int n;
	scanf("%d", &n);
	int lengths[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &lengths[i]);
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				int perimeter = lengths[i] + lengths[j] + lengths[k];
				int ma = maxi(lengths[i], maxi(lengths[j], lengths[k]));
				int rest = perimeter - ma;
				if(rest > ma)
					answer = maxi(perimeter, answer);
			}
		}
	}
	printf("%d", answer);
	return 0;
}
int maxi(int a, int b){
	int returnVal;
	if(a > b)
		returnVal = a;
	else
		returnVal = b;
	return returnVal;
}
