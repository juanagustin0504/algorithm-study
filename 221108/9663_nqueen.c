#include <stdio.h>
int queens[15][15];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int findQueen = 0;

void dfs(int n, int y, int x, int (*map)[15]) {
	int d;
	for(d=0;d<8;d++) {
		int ny = y + di[d];
		int nx = x + dj[d];
		
		while(ny < 0 && ny >= n && nx < 0 && nx >= n) {
			if(map[ny][nx] == 1) {
				findQueen = 1;
				return;
			}
			ny += di[d];
			nx += dj[d];
		}
		
	}
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	int map[15][15] = {0,};
	int visitMap[15][15] = {0,};
	int i,j;
	int resultCnt = 0;
	
	int canRoop = 1;
	for(i=n;i>1;i--) {
		canRoop *= i;
	}
	
	while(canRoop--) {
		int queenCnt = n;
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				findQueen = 0;
				dfs(n, i, j, map);
				if(!findQueen) {
					map[i][j] = 1;
					queenCnt--;
					break;
				}
			}
		}
		if(queenCnt == 0) {
			resultCnt++;
		}
		printf("====================\n");
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				printf("%3d", map[i][j]);
				map[i][j] = 0;
			}
			printf("\n");
		}
		printf("====================\n");
	}
	printf("%d", resultCnt);
	
	
	
	return 0;
}
