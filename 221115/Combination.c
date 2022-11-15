// Combination
#include <stdio.h>

void comb(int depth, int start, int *num, int *visit, int *result) {
	if(depth == 2) {
		int i;
		for(i=0;i<2;i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		return;
	}
	int i, j;
	for(i=start;i<4;i++) {
		if(visit[i]) continue;
		visit[i] = 1;
		result[depth] = num[i];
		comb(depth + 1, i + 1, num, visit, result);
		visit[i] = 0;
	}
}

int main() {
	// 1 2 3 4
	// 2
	// 4p2
	
	int num[4] = {1, 2, 3, 4};
	int visit[4] = {0,};
	int result[2];
	
	comb(0, 0, num, visit, result);
	
	return 0;
}
