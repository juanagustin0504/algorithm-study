#include <stdio.h>
#include <stdlib.h>

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void dfs(int n, int m, int **map, int **visitMap, int y, int x, int **cntMap) {
	visitMap[y][x] = 1;
	int d;
	for(d=0;d<4;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		if(nx < 0 || nx >= m || ny < 0 || ny >= n || visitMap[ny][nx] == 1) continue;
		if(map[ny][nx] == 0) {
			cntMap[y][x] = cntMap[y][x] <= 0 ? -1 : cntMap[y][x]-1;
		} else {
			dfs(n, m, map, visitMap, ny, nx, cntMap);
		}
		
	}
}

int main() {
	int n, m;
	int i, j;
	
	scanf("%d %d", &n, &m);
	
	int **map = malloc(sizeof(int *) * n);
	int **visitMap = malloc(sizeof(int *) * n);
	int **cntMap = malloc(sizeof(int *) * n);
	for(i=0;i<n;i++) {
		map[i] = malloc(sizeof(int) * m);
		visitMap[i] = malloc(sizeof(int) * m);
		cntMap[i] = malloc(sizeof(int) * m);
	}
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d", &map[i][j]);
			visitMap[i][j] = 0;
			cntMap[i][j] = map[i][j];
		}
	}
	
	int year = 0;
	int landCnt = 0;
	while(1) {
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				if(map[i][j] != 0 && visitMap[i][j] == 0) {
					landCnt++;
					if(landCnt > 1) goto label;
					visitMap[i][j] == 1;
					dfs(n, m, map, visitMap, i, j, cntMap);
				}
			}
		}
		
		if(landCnt == 0) break;
		
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				map[i][j] = cntMap[i][j];
				if(cntMap[i][j] == -1) {
					map[i][j] = 0;
				}
				visitMap[i][j] = 0;
				cntMap[i][j] = map[i][j];
			}
		}
		landCnt = 0;
		year++;
	}
	
	label:
		if(landCnt == 0) printf("0");
		else printf("%d", year);
	
	return 0;
	
}
