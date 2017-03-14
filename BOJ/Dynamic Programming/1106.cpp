#include <stdio.h>
#define INF 987654321

int min(int X, int Y){ return X > Y ? Y : X; }
int D[1200], N, M, A[23][2];

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) scanf("%d %d", &A[i][0], &A[i][1]);
	for(int i=0; i<1200; i++) D[i] = INF;
	D[0] = 0;
	for(int i=0; i<=N; i++) if(D[i] != INF) for(int j=0; j<M; j++) D[i + A[j][1]] = min(D[i + a[j][1]], D[i] + A[j][0]);
	int ans = INF;
	for(int i=N; i<1200; i++) ans = min(ans, D[i]);
	printf("%d\n", ans);
}
