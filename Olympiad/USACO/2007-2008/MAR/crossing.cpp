#include <stdio.h>

int N, M, D[2505], A[2505];
int min(int X, int Y){ return X > Y ? Y : X; }

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", A+i), A[i] += A[i-1];
	for(int i=1; i<=N; i++) {
		D[i] = 2e9;
		for(int j=0; j<i; j++) D[i] = min(D[i], D[j] + A[i-j] + M * 2);
	}
	printf("%d", D[N] - M);
}
