#include <stdio.h>
#define INF 987654321

int N, K, D[503][503], A[503][2];
int abs(int x){ return x > 0 ? x : -x; }
int C(int x, int y){ return abs(A[x][0] - A[y][0]) + abs(A[x][1] - A[y][1]); }
int min(int X, int Y){ return X > Y ? Y : X; }

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]);
	for(int i=0; i<=N; i++) for(int j=0; j<=K; j++) D[i][j] = INF;
	D[0][0] = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<=K; j++) {
			if(D[i][j]!=INF) {
				for(int k=i+1; k<=N; k++) {
					if(j + k - i - 1 > K) break;
					D[k][j+k-i-1] = min(D[k][j+k-i-1], D[i][j] + C(i, k));
				}
			}
		}
	}
	int ans = INF;
	for(int i=0; i<=K; i++) ans = min(ans, D[N-1][i]);
	printf("%d", ans);
} 
