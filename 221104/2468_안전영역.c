#include <stdio.h>

int landCnt = 0;
int maxLandCnt = 0;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void dfs(int n, int y, int x, int (*map)[100], int (*visitMap)[100], int limit) {
	visitMap[y][x] = 1;
	int d;
	for(d=0;d<4;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		if(ny < 0 || ny >= n || nx < 0 || nx >= n || visitMap[ny][nx] == 1 || map[ny][nx] <= limit) continue;
		dfs(n, ny, nx, map, visitMap, limit);
	}
}

int main() {
	int map[100][100] = {0,};
	int visitMap[100][100] = {0,};
	
	int i, j;
	int n, max = 0;
	
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &map[i][j]);
			if(max < map[i][j])
				max = map[i][j];
		}
	}
	int limit = 0;
	while(limit < max) {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(map[i][j] > limit && visitMap[i][j] == 0) {
					landCnt++;
					dfs(n, i, j, map, visitMap, limit);
				}
			}
		}
		if(landCnt > maxLandCnt)
			maxLandCnt = landCnt;
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				visitMap[i][j] = 0;
			}
		}
		limit++;
		landCnt = 0;
	}
	
	printf("%d", maxLandCnt);
	
	
	return 0;
}
