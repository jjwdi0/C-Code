#include <stdio.h>

int N, M, cnt, d[4][2]={1, 0, -1, 0, 0, 1, 0, -1};
char A[111][111];
bool chk[111][111];
bool get(int x, int y){ return !(x < 0 || y < 0 || x >= N || y >= M || chk[x][y] || A[x][y] == '.'); }

int dfs(int x, int y) {
	chk[x][y] = 1;
	int res = 1;
	for(int i=0; i<4; i++) {
		int xx = x + d[i][0], yy = y + d[i][1];
		if(get(xx, yy)) res += dfs(xx, yy);
	}
	return res;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	for(int i=0; i<N; ++i) for(int j=0; j<M; j++) if(!chk[i][j] && A[i][j] == '#') cnt += !!dfs(i, j);
	printf("%d", cnt);
}
