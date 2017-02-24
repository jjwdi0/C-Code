#include <stdio.h>
int D[55][55][55][55], N, M, A[55][55], sum[55][55];
int min(int X, int Y) { return X<Y?X:Y; }
int f(int x, int y, int z, int w) {
	if(D[x][y][z][w]) return D[x][y][z][w];
	if(x == z && y == w) return 0;
	int res = 2e9;
	for(int i=x; i<z; i++) res = min(res, sum[z][w] - sum[x-1][w] - sum[z][y-1] + sum[x-1][y-1] + f(x, y, i, w) + f(i + 1, y, z, w));
	for(int i=y; i<w; i++) res = min(res, sum[z][w] - sum[x-1][w]-sum[z][y-1]+sum[x-1][y-1]+f(x, y, z, i)+f(x, i + 1, z, w));
	return D[x][y][z][w] = res;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &A[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) sum[i][j] = A[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
	printf("%d\n", f(1, 1, N, M));
}
