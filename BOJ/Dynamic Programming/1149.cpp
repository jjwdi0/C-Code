#include <stdio.h>

int D[1005][3], N, A[1005][3];
int min(int x, int y) { return x > y ? y : x; }

int f(int x, int y) {
	if(D[x][y]) return D[x][y];
	if(x == 0) return D[0][y] = A[x][y];
	if(y == 0) return D[x][y] = min(f(x - 1, 1), f(x - 1, 2)) + A[x][y];
	if(y == 1) return D[x][y] = min(f(x - 1, 0), f(x - 1, 2)) + A[x][y];
	return D[x][y] = min(f(x - 1, 1), f(x - 1, 0)) + A[x][y];
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) for(int j=0; j<3; j++) scanf("%d", &A[i][j]);
	printf("%d", min( min( f(N, 0), f(N, 1) ), f(N, 2) ) );
}
