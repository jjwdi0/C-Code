#include <stdio.h>
#define INF 987654321

int N, M, A[1003], B[1003], D[1003][1003];
int min(int X, int Y){ return X > Y ? Y : X; }

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", A+i);
	for(int i=1; i<=M; i++) scanf("%d", B+i);
	for(int i=0; i<=M; i++) for(int j=0; j<=N; j++) D[i][j] = INF;
	D[0][0] = 0;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			if(D[i][j]!=INF) {
				D[i+1][j+1] = min(D[i+1][j+1], D[i][j] + A[j+1] * B[i+1]);
				D[i+1][j] = min(D[i+1][j], D[i][j]);
			}
		}
	}
	int ans = INF;
	for(int i=0; i<=M; i++) ans = min(ans, D[i][N]);
	printf("%d", ans);
}
