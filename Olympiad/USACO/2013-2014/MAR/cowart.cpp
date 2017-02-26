#include <stdio.h>

int N, ans, dx[4][2] = {-1, 0, 0, 1, 0, -1, 1, 0};
char A[103][103];
bool visited[103][103];

bool get(int x, int y){return !(x<0 || y<0 || x>=N || y>=N);}

void dfs(int x, int y) {
	visited[x][y] = 1;
	for(int i=0; i<4; i++) {
		int xx = x + dx[i][0], yy = y + dx[i][1];
		if(get(xx, yy) && !visited[xx][yy] && A[xx][yy] == A[x][y]) dfs(xx, yy);
	}
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", A+i);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(!visited[i][j]) ans++, dfs(i, j);
	printf("%d ", ans);
	ans = 0;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
		if(A[i][j] == 'G') A[i][j] = 'R';
		visited[i][j] = 0;
	}
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(!visited[i][j]) ans++, dfs(i, j);
	printf("%d\n", ans);
}
