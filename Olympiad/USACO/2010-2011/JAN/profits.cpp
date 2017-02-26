#include <stdio.h>

int N, ans = -987654321, sum;

int max(int X, int Y){ return X > Y ? X : Y; }

int main() {
	scanf("%d", &N);
	for(int i=0, x; i<N; i++) {
		scanf("%d", &x);
		sum = max(sum + x, x);
		ans = max(ans, sum);
	}
	printf("%d", ans);
}
