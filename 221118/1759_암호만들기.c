#include <stdio.h>

void sort(int n, char *words) {
	int i, j;
	for(i=0;i<n-1;i++) { // bouble sort
		for(j=i;j<n;j++) {
			if(words[i] > words[j]) {
				// swap
				char temp = words[i];
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}
}

int checkMouem(char word) {
	if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u') {
		return 1;
	}
	return 0;
}

void comb(int l, int c, int start, char *words, int *visit, int depth, char *result) {
	if(depth == l) {
		int i;
		int mouemCnt, jauemCnt;
		mouemCnt = jauemCnt = 0;
		for(i=0;i<l;i++)
			if(checkMouem(result[i])) mouemCnt++;
			else jauemCnt++;
		if(mouemCnt > 0 && jauemCnt > 1) {
			for(i=0;i<l;i++)
				printf("%c", result[i]);
			printf("\n");
		}
		return;
	} else {
		int i=0;
		for(i=start;i<c;i++) {
			if(visit[i]) continue;
			visit[i] = 1;
			result[depth] = words[i];
			comb(l, c, i + 1, words, visit, depth + 1, result);
			visit[i] = 0;
		}
	}
}

int main() {
	
	char words[15];
	int visit[15] = {0,};
	char result[15];
	int l, c;
	scanf("%d%d", &l, &c);
	
	int i;
	for(i=0;i<c;i++) {
		scanf(" %c", &words[i]);
	}
	
	sort(c, words);
	
	comb(l, c, 0, words, visit, 0, result);
	
	
	return 0;
}
