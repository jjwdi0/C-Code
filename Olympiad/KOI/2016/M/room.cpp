#include <stdio.h>

int N, K, A, B[2][2], cnt;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0, x, y; i<N; i++) {
		scanf("%d %d", &x, &y);
		if(y < 3) A++;
		else B[x][(y-3)/2]++;
	}
	for(int i=0; i<2; i++) for(int j=0; j<2; j++) cnt += (B[i][j] ? (B[i][j] - 1) / K + 1 : 0);
	printf("%d", (A ? (A - 1) / K + 1 : 0) + cnt);
}
