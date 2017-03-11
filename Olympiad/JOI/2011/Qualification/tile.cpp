#include <stdio.h>

int N, T;

int main() {
	scanf("%d %d", &N, &T);
	while(T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if(a >= (N + 2) / 2) a = N - a + 1;
		if(b >= (N + 2) / 2) b = N - b + 1;
		if(b >= a && b <= (N - a + 1)) printf("%d\n", (a - 1) % 3 + 1);
		else printf("%d\n", (b - 1) % 3 + 1);
	}
}
