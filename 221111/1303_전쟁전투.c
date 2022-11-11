#include <stdio.h>
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int length = 0;
int bScore = 0;
int wScore = 0;

void dfs(int n, int m, char (*map)[100], int (*visitMap)[100], int y, int x, char team) {
	int d;
	for(d=0;d<4;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		if(ny < 0 || ny >= m || nx < 0 || nx >= n || visitMap[ny][nx] == 1 || map[ny][nx] != team) continue;
		visitMap[ny][nx] = 1;
		length++;
		dfs(n, m, map, visitMap, ny, nx, team);
	}
}

int main() {
	int n, m, i, j;
	char map[100][100];
	int visitMap[100][100] = {0,};
	
	scanf("%d%d", &n, &m);
	
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			if(visitMap[i][j] == 0) {
				length = 1;
				visitMap[i][j] = 1;
				char team;
				if(map[i][j] == 'W') {
					team = 'W';
				} else {
					team = 'B';
				}
				dfs(n, m, map, visitMap, i, j, team);
				if(team == 'W')
					wScore += (length * length);
				else
					bScore += (length * length);
			}
		}
	}
	printf("%d %d", wScore, bScore);
	
	
	return 0;
}
