#include <stdio.h>
#define INF 987654321

int N, A[503][503], M;
int min(int X, int Y){ return X > Y ? Y : X; }

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) A[i][j] = INF;
	while(M--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		A[t1][t2] = A[t2][t1] = 1;
	}
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
		if(A[j][i] == INF) continue;
		for(int k=1; k<=N; k++) A[j][k] = min(A[j][k], A[j][i] + A[i][k]);
	}
	int ans = 0;
	for(int i=2; i<=N; i++) if(A[1][i] <= 2) ans++;
	printf("%d", ans);
}
