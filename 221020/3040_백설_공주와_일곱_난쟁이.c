#include <stdio.h>

void main() {
	
	int size = 9, i, j;
	int people[size];
	int sum = 0;
	int idx1, idx2;
	
	for (i = 0; i < size; i++) {
		scanf("%d", &people[i]);
	}
	
	for (i = 0; i < 9; i++) {
		sum += people[i];
	}
	
	sum -= 100;
	
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (people[i] + people[j] == sum) {
				idx1 = i;
				idx2 = j;
				i = 8;
				break;
			}
		}
	}
	
	for (i = 0; i < 9; i++) {
		if (i == idx1 || i == idx2) continue;
		printf("%d\n", people[i]);
	}
	
}
