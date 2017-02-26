#include <stdio.h>
#define INF 987654321

int V, E, A[111][111], L[11111], cnt;
int min(int X, int Y){ return X > Y ? Y : X; }

int main() {
	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++) scanf("%d", L+i);
	for(int i=0; i<=V; i++) for(int j=0; j<=V; j++) A[i][j] = INF;
	for(int i=1; i<=V; i++) for(int j=1; j<=V; j++) scanf("%d", &A[i][j]);
	for(int i=1; i<=V; i++) for(int j=1; j<=V; j++) for(int k=1; k<=V; k++) A[j][k] = min(A[j][k], A[j][i] + A[i][k]);
	for(int i=0; i<E-1; i++) cnt += A[L[i]][L[i+1]];
	printf("%d", cnt);
}
