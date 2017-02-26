#include <stdio.h>

int d[8][2]={1, 0, 0, 1, -1, 0, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1}, N, M, ans;
int max(int X, int Y){ return X > Y ? X : Y; }

char A[777][777];
bool visited[777][777];

char get(int x, int y){return (x<0 || y<0 || y>=M || x>=N || visited[x][y]) ? 0 : A[x][y];}

int dfs(int x, int y) {
	visited[x][y] = 1;
	int res = 1;
	for(int i=0; i<8; i++) if(get(x+d[i][0], y+d[i][1]) == '.') res += dfs(x+d[i][0], y+d[i][1]);
	return res;
}

int main() {
	scanf("%d %d", &N, &M);
	N ^= M ^= N ^= M;
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(A[i][j] == '.' && !visited[i][j]) ans = max(ans, dfs(i, j));
	printf("%d", ans);
}
