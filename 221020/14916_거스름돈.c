#include <stdio.h>

int main() {
	
	int remain, won5Cnt = 0, won2Cnt = 0;
	scanf("%d", &remain);
	
	if (remain == 1 || remain == 3) {
		printf("-1");
		return 0;
	} 
	
	if (remain % 5 == 0) {
		won5Cnt = remain / 5;
	} else {
		won5Cnt = remain / 5;
		remain %= 5;
		
		won2Cnt = remain / 2;
		remain %= 2;
		
		if (remain != 0) {
			won5Cnt--;
			remain += 5;
			
			won2Cnt += remain / 2;	
		}
	}
	
	printf("%d", won5Cnt + won2Cnt);
	
}
