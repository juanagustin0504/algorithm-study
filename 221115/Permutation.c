// Permutation
#include <stdio.h>

void perm(int depth, int *result, int *visit, int *num) {
	if(depth == 2) {
		int i;
		for(i=0;i<2;i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		return;
	}
	int i, j;
	for(i=0;i<4;i++) {
		if(visit[i]) continue;
		visit[i] = 1;
		result[depth] = num[i];
		perm(depth + 1, result, visit, num);
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
	
	perm(0, result, visit, num);
	
	return 0;
}
