#include <stdio.h>

int N, Q, A[100005][3];

int main() {
	scanf("%d %d", &N, &Q);
	for(int i=1, x; i<=N; i++) scanf("%d", &x), A[i][x-1] = 1;
	for(int i=1; i<=N; i++) A[i][0] += A[i-1][0], A[i][1] += A[i-1][1], A[i][2] += A[i-1][2];
	for(int i=0, x, y; i<Q; i++) scanf("%d %d", &x, &y), printf("%d %d %d\n", A[y][0] - A[x-1][0], A[y][1] - A[x-1][1], A[y][2] - A[x-1][2]);
}
