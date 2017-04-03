#include <stdio.h>

char A[5005], B[5005];
int N, lcs[5005][5005];
int max(int X, int Y) { return X>Y?X:Y; }

int main() {
	scanf("%d", &N);
	scanf("%s", A);
	for(int i=0; i<n; i++) B[N-i-1] = A[i];
	for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {
		if(A[i-1] == B[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
		else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
	}
	printf("%d", N-lcs[n][n]);
}
