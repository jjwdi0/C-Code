#include <stdio.h>

int a[103][103], n, m, k, ans, dx[4][2]={-1, 0, 1, 0, 0, -1, 0, 1};
int max(int X, int Y){ return X > Y ? X : Y; }

int dfs(int x, int y) {
	a[x][y] = 0;
	int ret = 1;
	for(int i=0; i<4; i++) {
		int xx = x + dx[i][0], yy = y + dx[i][1];
		if(xx <= 0 || xx > n || yy <= 0 || yy > m || !a[xx][yy]) continue;
		ret += dfs(xx, yy);
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0, x, y; i<k; i++) {
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(a[i][j]) ans = max(ans, dfs(i, j));
	printf("%d", ans);
}
