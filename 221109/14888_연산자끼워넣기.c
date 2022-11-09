#include <stdio.h>
int max = -1000000000;
int min = 1000000000;

int dfs(int n, int *arr, int plus, int minus, int mul, int div, int idx, int sum) {
	if(idx == n - 1) {
		if(max < sum)
			max = sum;
		if(min > sum)
			min = sum;
	}
	if(plus > 0) {
		dfs(n, arr, plus - 1, minus, mul, div, idx + 1, sum + arr[idx + 1]);
	}
	if(minus > 0) {
		dfs(n, arr, plus, minus - 1, mul, div, idx + 1, sum - arr[idx + 1]);
	}
	if(mul > 0) {
		dfs(n, arr, plus, minus, mul - 1, div, idx + 1, sum * arr[idx + 1]);
	}
	if(div > 0) {
		dfs(n, arr, plus, minus, mul, div - 1, idx + 1, sum / arr[idx + 1]);
	}
}

int main() {
	int n, arr[11], plus, minus, mul, div;
	
	scanf("%d", &n);
	
	int i, j;
	for(i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}
	
	scanf("%d%d%d%d", &plus, &minus, &mul, &div);
	
	dfs(n, arr, plus, minus, mul, div, 0, arr[0]);
	
	printf("%d\n%d", max, min);	
	
	return 0;
}
