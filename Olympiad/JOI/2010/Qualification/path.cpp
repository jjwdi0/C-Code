#include <stdio.h>
#define MOD 100000

int D[103][103][2], N, M;
int min(int X, int Y){ return X > Y ? Y : X; }

int f(int x, int y, int z) {
	if(~D[x][y][z]) return D[x][y][z];
	if(x == N && y == M) return D[x][y][z] = 1;
	D[x][y][z] = 0;
	if(z == 0) {
		for(int i = (x == N ? min(y + 2, M) : y + 2); i <= M; i++) D[x][y][z] += f(x, i, 1);
	}
	else {
		for(int i = (y == M ? min(x + 2, N) : x + 2); i <= N; i++) D[x][y][z] += f(i, y, 0);
	}
	D[x][y][z] %= MOD;
	return D[x][y][z];
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<=N; i++) for(int j=0; j<=M; j++) D[i][j][0] = D[i][j][1] = -1;
	printf("%d", (f(1, 0, 0) + f(0, 1, 1)) % MOD);
}
