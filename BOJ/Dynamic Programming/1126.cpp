#include <stdio.h>
#define NUM 500000

int N, A[55], D[2][1111111];
int max(int X, int Y){ return X > Y ? X : Y; }

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<2*NUM; i++) D[0][i] = D[1][i] = -1;
	D[0][NUM] = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<=2*NUM; j++) {
			if(~D[i&1][j]) {
				D[(i + 1) & 1][j] = max(D[(i + 1) & 1][j], D[i & 1][j]);
				if(j + A[i] <= 2 * NUM) D[(i + 1) & 1][j + A[i]] = max(D[(i + 1) & 1][j + A[i]], D[i & 1][j] + A[i]);
				if(j - A[i] >= 0) D[(i + 1) & 1][j - A[i]] = max(D[(i + 1) & 1][j - A[i]], D[i & 1][j]);
			}
		}
	}
	printf("%d", D[N & 1][NUM] ? D[N & 1][NUM] : -1);
}
