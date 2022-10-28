#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int dfs(int n, int m, int **map, int **visitMap, int i, int j, int size) {
	
	visitMap[i][j] = 1;
	
	int d;
	for(d=0;d<4;d++) {
		int ni = i + di[d];
		int nj = j + dj[d];
		
		if(ni < 0 || ni >= n || nj < 0 || nj >= m || map[ni][nj] == 0 || visitMap[ni][nj] == 1) continue;
		size = dfs(n, m, map, visitMap, ni, nj, ++size);
	}
	
	return size;
}

int main() {
	
	int n, m, k, r, c;
	scanf("%d %d %d", &n, &m, &k);
	
	int i, j;
	int **map = malloc(sizeof(int *) * n);
	int **visitMap = malloc(sizeof(int *) * n);
	for(i=0;i<n;i++) {
		map[i] = malloc(sizeof(int) * m);
		visitMap[i] = malloc(sizeof(int) * m);
	}
	
//	for(i=0;i<n;i++) {
//		for(j=0;j<m;j++) {
//			map[i][j] = 0;
//			visitMap[i][j] = 0;
//		}
//	}
	for(i=0;i<n;i++) {
		memset(map[i], 0, sizeof(int) * m);	
		memset(visitMap[i], 0, sizeof(int) * m);
	}
	
	for(i=0;i<k;i++) {
		scanf("%d %d", &r, &c);
		map[r-1][c-1] = 1;
	}
	
	int max = 0;
	
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			if(map[i][j] == 1 && visitMap[i][j] != 1) {
				int curSize = dfs(n, m, map, visitMap, i, j, 1);
				if(curSize>max) max = curSize;
			}
		}
	}
	
	printf("%d", max);
	
	return 0;
}
