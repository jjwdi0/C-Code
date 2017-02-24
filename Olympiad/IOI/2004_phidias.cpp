#include <stdio.h>

int W, H, N, A[222][2], D[666][666];
int min(int X, int Y){return X>Y?Y:X;}

int main() {
	scanf("%d %d", &W, &H);
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]);
	for(int i=1; i<=W; i++) for(int j=1; j<=H; j++) {
		D[i][j] = 2e9;
		for(int k=0; k<N; k++) {
			if(i - A[k][0] < 0 || j - A[k][1] < 0) continue;
			D[i][j] = min(min(D[i][j], D[i-A[k][0]][j] + D[A[k][0]][j-A[k][1]]), D[i][j-A[k][1]] + D[i-A[k][0]][A[k][1]]);
		}
		if(D[i][j] > 1e9) D[i][j] = i * j;
	}
	printf("%d", D[W][H]);
}
