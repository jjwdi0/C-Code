#include <stdio.h>

int N, M, p, q;
int min(int X, int Y){ return X > Y ? Y : X; }

int main() {
	scanf("%d %d", &N, &M);
	p = q = 1e9;
	for(int i=0, x, y; i<M; i++) {
		scanf("%d %d", &x, &y);
		p = min(p, x);
		q = min(q, y);
	}
	printf("%d", min(p * (N / 6) + q * (N % 6), min(q * N, p * (N / 6 + !!(N % 6)))));
}
