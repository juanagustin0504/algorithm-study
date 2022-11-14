#include <stdio.h>
#define n 5
#define m 5

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int resultCnt = 0;
int visitResultMap[5][5] = {0,};

void dfs(char (*map)[5], int (*visitMap)[5], int y, int x, int length, int sCount) {
	int visitCpyMap[5][5] = {0,};
	int i, j;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			visitCpyMap[i][j] = visitMap[i][j];
		}
	}
	visitMap[y][x] = 1;
	visitCpyMap[y][x] = 1;
	if(length == 7) {
		if (sCount >= 4) {
			resultCnt++;
			for(i=0;i<5;i++) {
				for(j=0;j<5;j++) {
					visitResultMap[i][j] = visitCpyMap[i][j];
				}
			}
		}
		return;
	}
	
	int d;
	for(d=0;d<4;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		if(nx < 0 || nx >= m || ny < 0 || ny >= n || visitCpyMap[ny][nx] == 1) continue;
		int temp = 0;
		if(map[ny][nx] == 'S') {
			temp = 1;
		}
		
		dfs(map, visitCpyMap, ny, nx, length + 1, sCount + temp);
	}
}

int main() {
	
	char map[5][5];
	int i, j;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			int visitMap[5][5] = {0,};
			dfs(map, visitMap, i, j, 1, 0);
			int k,l;
			printf("=============%d %d==============\n", i, j);
			for(k=0;k<5;k++) {
				for(l=0;l<5;l++) {
					printf("%2d", visitResultMap[k][l]);
				}
				printf("\n");
			}
			printf("=============================\n");
		}
	}
	
	printf("%d", resultCnt);
	
	return 0;
}
