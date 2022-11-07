#include <stdio.h>

int dfs(int n1, int n2, int cnt) {
	if (cnt) {
		return dfs(n2, (n1 + n2), --cnt);	
	}
	return n2;
}


int main() {
	
	int n;
	scanf("%d", &n);
	
	if(n<2) {
		printf("%d", n);
		return 0;
	}
	
	int i, j;
	int temp1 = 1, temp2 = 1, temp3 = 0;
	/* 1 */
//	n -= 2;
//	while(n--) {
//		temp3 = temp1 + temp2;
//		temp1 = temp2;
//		temp2 = temp3;
//	}
//	
//	printf("%d", temp3);

	/* 2 */
	printf("%d", dfs(0, 1, n - 1));
	
	
	return 0;
}
