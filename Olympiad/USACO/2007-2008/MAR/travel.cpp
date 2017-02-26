#include <stdio.h>

int N, M, K, x1, x2, y1, y2, D[103][103][16], d[4][2]={-1, 0, 1, 0, 0, 1, 0, -1};
char A[103][103];

bool get(int x, int y) { return A[x][y] == '.'; }
int main() {
	scanf("%d %d %d", &N, &M, &K);
	for(int i=1; i<=N; i++) scanf("%s", A[i] + 1);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	D[x1][y1][0] = 1;
	for(int ti=0; ti<K; ti++) for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) if(D[i][j][ti]) for(int k=0; k<4; k++) {
		int x = i + d[k][0], y = j + d[k][1];
		if(get(x, y)) D[x][y][ti+1] += D[i][j][ti];
	}
	printf("%d", D[x2][y2][K]);
}
