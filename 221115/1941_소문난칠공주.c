#include <stdio.h>
int resCnt = 0;

void comb(int depth, int start, char (*map)[5], int (*visit)[5], char *result, int sCount) {
	printf("======================\n");
	printf("%d %d %d %s\n", depth, start, sCount, result);
	if(depth == 7) {
		if(sCount >= 4) {
			resCnt++;
			
//			printf("%s", result);
//			printf("\n");
		}
		return;
	}
	int i, j;
	for(i=start/5;i<5;i++) {
		for(j=start%5;j<5;j++) {
			if(visit[i][j]) continue;
			visit[i][j] = 1;
			result[depth] = map[i][j];
			int temp = 0;
			if (map[i][j] == 'S') temp = 1;
			comb(depth + 1, ((i * 5) + (j + 1)), map, visit, result, sCount + temp);
			visit[i][j] = 0;
		}
	}
}

	
int main() {
//	YYYYY
//	SYSYS
//	YYYYY
//	YSYYS
//	YYYYY
	// 7
	// 25c7
	
	char map[5][6];
	int visit[5][5] = {0,};
	char result[8];
	
	int i, j;
	for(i=0;i<5;i++) {
		for(j=0;j<5;j++) {
			scanf(" %c", &map[i][j]);
		}
		map[i][j] = '\0';
	}
	
	comb(0, 0, map, visit, result, 0);
	
	printf("%d\n", resCnt);
	
	return 0;
}
