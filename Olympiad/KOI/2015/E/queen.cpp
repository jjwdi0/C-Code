#include <stdio.h>

int N, Q, A[1405], B[707][707];

int main() {
	scanf("%d %d", &N, &Q);
	for(int i=0, x, y, z; i<Q; i++) {
		scanf("%d %d %d", &x, &y, &z);
		int r = 1;
		A[r]++, r += x;
		A[r]++, r += y;
		A[r]++;
	}
	for(int i=1; i<N*2; i++) A[i] += A[i-1];
	for(int i=1; i<N; i++) B[N-i+1][1] = A[i] - Q + 1;
	for(int i=N; i<N*2; i++) B[1][i-N+1] = A[i] - Q + 1;
	for(int i=1; i<=N; puts(""), i++) for(int j=1; j<=N; j++) {
		if(i == 1 || j == 1) printf("%d ", B[i][j]);
		else printf("%d ", B[i][j] = B[i-1][j]);
	}
}
