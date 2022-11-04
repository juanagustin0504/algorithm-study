#include <stdio.h>

// 1 2 3
// 4   5
// 6 7 8
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int isPeak = 0;

void dfs(int n, int m, int y, int x, int (*map)[70], int (*visitMap)[70]) {
	visitMap[y][x] = 1;
	int d;
	for(d=0;d<8;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if(map[ny][nx] > map[y][x]) isPeak = 0;
		if(map[ny][nx] != map[y][x] || visitMap[ny][nx] == 1) continue;
		dfs(n, m, ny, nx, map, visitMap);
	}
}

int main() {
	
	int map[100][70] = {0,};
	int visitMap[100][70] = {0,};
	
	int i, j;
	int n, m;
	
	int peakCnt = 0;
	
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			if(visitMap[i][j] == 0) {
				isPeak = 1;
				dfs(n, m, i, j, map, visitMap);
				if(isPeak)
					peakCnt++;
			}
		}
	}
	
	printf("%d", peakCnt);
	
	return 0;
}
