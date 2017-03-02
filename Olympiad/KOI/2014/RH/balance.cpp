#include <stdio.h>
#define INF 987654321

int A[103][103], B[103][103], N, M, cnt;

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) A[i][j] = B[i][j] = INF;
	for(int i=0, x, y; i<M; i++) {
		scanf("%d %d", &x, &y);
		A[x][y] = B[y][x] = 1;
	}
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) for(int k=1; k<=N; k++) {
		if(A[j][k] > A[j][i] + A[i][k]) A[j][k] = A[j][i] + A[i][k];
		if(B[j][k] > B[j][i] + B[i][k]) B[j][k] = B[j][i] + B[i][k];
	}
	for(int i=1; i<=N; i++) {
		cnt = 0;
		for(int j=1; j<=n; j++) if(A[i][j] < INF) cnt++;
		for(int j=1; j<=n; j++) if(B[i][j] < INF) cnt++;
		printf("%d\n", N - cnt - 1);
	}
}
