#include <stdio.h>

char a[1003][1003];
int n, i, j, g[1003][1003], cnt, visited[1003][1003];

void dfs(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= n) return;
	if(a[x][y] != '*' || visited[x][y] == 1) return;
	visited[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int main() {
	scanf("%d\n", &n);
	for(i=0; i<n; i++) gets(a[i]);
	for(i=0; i<n; i++) for(j=0; j<n; j++) if(a[i][j]=='*' && visited[i][j]==0) dfs(i, j), cnt++;
	printf("%d\n", cnt);
}
