#include <stdio.h>

void dfs(int n, int m, int cnt, int *arr) {
	if(cnt == m) {
		int i;
		for(i=0;i<m;i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	} else {
		int i;
		for(i=1;i<=n;i++) {
			int exit = 0;
			int j;
			for(j=0;j<cnt;j++) {
				if(arr[j]==i) {
					exit = 1;
				}
			}
			if(!exit) {
				arr[cnt] = i;
				dfs(n, m, cnt+1, arr);
			}
		}
	}
	
	
}

int main() {
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	int i, j;
	int arr[8];
	dfs(n, m, 0, arr);
	
	return 0;
}
