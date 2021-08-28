#include <stdio.h>

/* symbolic constants */
#define MAX_LENGTH 100

void dfs(int x, int y);
char field[MAX_LENGTH][MAX_LENGTH+1];
int n, m;



int main(void){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s", field[i]);
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(field[i][j] == 'W'){
				dfs(i, j);
				count++;
			}
		}
	}
	printf("%d", count);
}

void dfs(int x, int y){
	field[x][y] = '.';
	/* processing squares around the current location (x, y)*/
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			if(x+dx < 0 || x+dx >= n || y + dy < 0 || y + dy >= m)
				continue;
			if(field[x + dx][y + dy] == 'W')
				dfs(x + dx, y + dy);
		}
	}
} 
