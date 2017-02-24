#include <stdio.h>

int D[35][35], N, M, K, cx, cy;

int f(int x, int y)
{
	if(D[x][y]) return D[x][y];
	if(x == y || y == 0) return D[x][y] = 1;
	return D[x][y] = f(x - 1, y - 1) + f(x - 1, y);
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	K = K ? K : 1;
	cx = (K - 1) / M, cy = (K - 1) % M;
	printf("%d", f(cx + cy, cx) * f(N - 1 - cx + M - 1 - cy, N - 1 - cx));
}
