#include <stdio.h>
int min = 0;
int max = 0;
int resCnt = 0;

void comb(int n, int l, int r, int x, int start, int *problem, int *visit, int depth, int sum, int *result) {
	if(sum>r) return;
	if(depth >= 1 && sum >= l && sum <= r) {
		min = max = result[0];
		int i;
		for(i=1;i<depth;i++) {
			if(min > result[i]) min = result[i];
			if(max < result[i]) max = result[i];
		}
		if(max - min >= x) resCnt++;
	}
	int i;
	for(i=start;i<n;i++) {
		if(visit[i]) continue;
		visit[i] = 1;
		result[depth] = problem[i];
		comb(n, l, r, x, i + 1, problem, visit, depth + 1, sum + problem[i], result);
		visit[i] = 0;
	}
}

int main() {
	int n, l, r, x;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	int i, j;
	int problem[15], result[15];
	int visit[15] = {0,};
	for(i=0;i<n;i++) {
		scanf("%d", &problem[i]);
	}
	comb(n, l, r, x, 0, problem, visit, 0, 0, result);
	printf("%d", resCnt);
	return 0;
}
