#include <stdio.h>
#define INF 1987654321
#define FOR(i,j,k) for((i)=(j);(i)<=(k);(i)++)

int D[103][103][103][4], N, A[3][103], sz[3], ind[3];

int min(int X, int Y){return X>Y?Y:X;}
int abs(int x){return x>0?x:-x;}

int f(int x, int y)
{
	int num[3];
	if(x == 0) {
		num[0] = A[0][ind[0]-1];
		num[1] = (num[0] + N / 3 -1) % N + 1;
		num[2] = (num[0] + N / 3 * 2 - 1) % N + 1;
	}
	if(x == 1)
	{
		num[1] = A[1][ind[1]-1];
		num[0] = (num[1] + N / 3 * 2 - 1) % N + 1;
		num[2] = (num[1] + N / 3 - 1) % N + 1;
	}
	if(x == 2) {
		num[2] = A[2][ind[2]-1];
		num[0] = (num[2] + N / 3 -1) % N + 1;
		num[1] = (num[2] + N / 3 * 2 - 1) % N + 1;
	}
	return abs(num[y] - A[y][ind[y]]);
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<3; i++) {
		scanf("%d", sz+i);
		for(int j=0; j<sz[i]; j++) scanf("%d", &A[i][j]);
	}
	for(int i=0; i<=sz[0]+1; i++) for(int j=0; j<=sz[1]+1; j++) for(int k=0; k<=sz[2]+1; k++) for(int p=0; p<3; p++) D[i][j][k][p] = INF;
	D[1][0][0][0] = min(A[0][0] - 1, N - A[0][0] + 1);
	D[0][1][0][1] = min(abs(A[1][0] - N / 3 - 1), N - abs(A[1][0] - N / 3 - 1));
	D[0][0][1][2] = min(abs(A[2][0] - N / 3 * 2 - 1), N - abs(A[2][0] - N / 3 * 2 - 1));
	FOR(ind[0],0,sz[0]) FOR(ind[1],0,sz[1]) FOR(ind[2],0,sz[2]) for(int p=0; p<3; p++) if(D[ind[0]][ind[1]][ind[2]][p] != INF) {
		D[ind[0]+1][ind[1]][ind[2]][0] = min(D[ind[0]+1][ind[1]][ind[2]][0], D[ind[0]][ind[1]][ind[2]][p] + min(abs(f(p, 0)), N - abs(f(p, 0))));
		D[ind[0]][ind[1]+1][ind[2]][1] = min(D[ind[0]][ind[1]+1][ind[2]][1], D[ind[0]][ind[1]][ind[2]][p] + min(abs(f(p, 1)), N - abs(f(p, 1))));
		D[ind[0]][ind[1]][ind[2]+1][2] = min(D[ind[0]][ind[1]][ind[2]+1][2], D[ind[0]][ind[1]][ind[2]][p] + min(abs(f(p, 2)), N - abs(f(p, 2))));
	}
	int ans = INF;
	for(int i=0; i<3; i++) ans = min(ans, D[sz[0]][sz[1]][sz[2]][i]);
	printf("%d", ans);
}
