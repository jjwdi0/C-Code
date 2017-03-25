#include <bits/stdc++.h>
using namespace std;

int D[103][10005], N, K, A[103], B[103], m = 2e9;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<N; i++) scanf("%d", B+i);
	for(int i=0; i<=N; i++) for(int j=0; j<=10000; j++) D[i][j] = -1;
	DT[0][0] = 0;
	DT[0][B[0]] = A[0];
	for(int i=1; i<=N; i++) for(int j=0; j<=10000; j++) {
		if(D[i-1][j] + 1) {
			D[i][j] = max(D[i][j], D[i-1][j]);
			D[i][j+B[i]] = max(D[i][j+B[i]], D[i-1][j] + A[i]);
		}
	}
	for(int i=0; i<=N; i++) for(int j=0; j<=10000; j++) if(DT[i][j] >= K) m = min(m, j);
	printf("%d\n", m);
}
