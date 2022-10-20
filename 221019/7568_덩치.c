#include <stdio.h>
#include <stdlib.h> 

int main() {
	
	int size, i, j;
	scanf("%d", &size);
	int* kgArr = malloc(sizeof(int) * size);
	int* cmArr = malloc(sizeof(int) * size);
	
	for(i = 0; i < size; i++) {
	   scanf("%d", &kgArr[i]);
	   scanf("%d", &cmArr[i]);
	}
	
	for(i = 0; i < size; i++) {
		int result = 1;
		for(j = 0; j < size; j++) { 
			if (i == j) { continue; }
			if (kgArr[i] < kgArr[j] && cmArr[i] < cmArr[j]) { result++; }
		}
		printf("%d ", result);
	}
	
	free(kgArr);
	free(cmArr);
}

