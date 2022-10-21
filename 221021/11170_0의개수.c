#include <stdio.h>

int f(int n) {
	int x, j, k, t;
	x = 0;
	for (t = 0, j = 1; j <= n; j *= 10, t++) {
		k = (n / j) % 10;
		if (!k) {
			x -= j - 1;
			x += n % j;
		}
		x += k * t * (j / 10);
	}
	
	return x;
}

int main() {
	int T;
	scanf("%d", &T);
	
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int s = f(b) - f(a);
		if (a == 0) s++;
		for (;a;a /= 10) {
			s += a % 10 == 0;
		}
		printf("%d\n", s);
	}
	
	
	return 0;
}
