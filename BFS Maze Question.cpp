/* Question Description
* There exist a maze n * m with the following symbols
* S = starting point, G = goal, # = Wall, . = Path
* Find the least number of steps from the start to the goal 
*/

#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;

/* define symbolic constants */
#define MAX_LENGTH 100
#define NUM_DIRECTIONS 4
#define INF 1000000

typedef pair<int, int> P;

int main(void){
	
	/* variable declaration */
	int n, m; // dimension of the maze
	char maze[MAX_LENGTH][MAX_LENGTH + 1]; // the actual maze
	int d[MAX_LENGTH][MAX_LENGTH]; // the shortest to each location in maze
	int sx, sy; // starting location
	int gx, gy; // goal location
	
	/* input */
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n; i++)
		scanf("%s", maze[i]);
	
	/* find start and end point */
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(maze[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			else if(maze[i][j] == 'G'){
				gx = i;
				gy = j;
			}
		}
	}
	
	queue <P> que; // queue variable to control the current event being processed 
	
	/* initialize route calculation array */
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			d[i][j] = INF;
	}
	/* setting the starting point */
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	
	/* implementation */
	int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
	while(que.size()){
		P current = que.front();
		que.pop(); // completed event 
		if(current.first == gx && current.second == gy) break; // if arrive, break loop 
		for(int i = 0; i < NUM_DIRECTIONS; i++){
			int newX = current.first + dx[i], newY = current.second+ dy[i];
			/* within boundary, not wall, never been there */
			if(newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] != '#' && d[newX][newY] == INF){
				d[newX][newY] = d[current.first][current.second] + 1; // min step to go there (bfs always find min steps)
				que.push(P(newX, newY)); // add to event list 
			}
		}
	}
	printf("%d", d[gx][gy]);
	return 0;
}  
