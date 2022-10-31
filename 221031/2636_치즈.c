#include <stdio.h>
#include <stdlib.h>

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void dfs(int n, int m, int **map, int y, int x, int **visitMap) {
	visitMap[y][x] = 1;
	int d;
	for(d=0;d<4;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 2 || visitMap[ny][nx] == 1) continue;
		if(map[ny][nx] == 1) {
			map[ny][nx] = 2;
			continue;
		}
		dfs(n, m, map, ny, nx, visitMap);
	}
}

int main() {
	int n, m, i, j, cheezeCnt = 0, year = 0;
	
	scanf("%d %d", &n, &m);
	
	int **map = malloc(sizeof(int *) * n);
	int **visitMap = malloc(sizeof(int *) * n);
	
	for(i=0;i<n;i++) {
		map[i] = malloc(sizeof(int) * m);
		visitMap[i] = malloc(sizeof(int) * m);
	}
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d", &map[i][j]);
			visitMap[i][j] = 0;
		}
	}
	
	while(1) {
		int cnt = 0;
		dfs(n, m, map, 0, 0, visitMap);
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				visitMap[i][j] = 0;
				if(map[i][j] == 2) {
					map[i][j] = 0;
					cnt++;
				}
			}
		}
		if(cnt == 0) {
			printf("%d\n%d", year, cheezeCnt);
			break;
		} else {
			cheezeCnt = cnt;
		}
		year++;
	}
	
	
	
	return 0;
}
