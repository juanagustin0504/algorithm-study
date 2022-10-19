#include <stdio.h>
#include <stdlib.h> 

int main() {
	
	int size, i, j;
	// 입력
	scanf("%d", &size);
	int* kgArr = malloc(sizeof(int) * size);
	int* cmArr = malloc(sizeof(int) * size);
	int* rank  = malloc(sizeof(int) * size);
	
	for(i = 0; i < size; i++) {
	   scanf("%d", &kgArr[i]);
	   scanf("%d", &cmArr[i]);
	   rank[i] = 1;
	}
	
	for(i = 0; i < size; i++)
		for(j = 0; j < size; j++) {
			if (i == j) continue;
			if (kgArr[i] < kgArr[j] && cmArr[i] < cmArr[j]) rank[i]++;
		}
	
	 
	// 결과 출력 
	for(i = 0; i < size - 1; i++)
		printf("%d ", rank[i]);
	printf("%d", rank[i]);
	
	free(kgArr);
	free(cmArr);
	free(rank);
}

