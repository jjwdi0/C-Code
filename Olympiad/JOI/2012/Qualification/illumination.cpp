#include <stdio.h>

int dx[6]={0, 0, -1, -1, 1, 1}, dy[6]={1, -1, 0, -1, 0, -1}, n, m, a[103][103], ans;
int dx2[6]={0, 0, -1, -1, 1, 1}, dy2[6]={1, -1, 0, 1, 0, 1};

int get(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= m) return -1;
	return a[x][y];
}

void dfs(int x, int y) {
	a[x][y] = 2;
	if(x % 2) for(int i=0; i<6; i++) if(get(x + dx[i], y + dy[i]) == 0) dfs(x + dx[i], y + dy[i]);
	else for(int i=0; i<6; i++) if(get(x + dx2[i], y + dy2[i]) == 0) dfs(x + dx2[i], y + dy2[i]);
}

int main() {
	scanf("%d%d", &m, &n);
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &a[i][j]);
	for(int i=0; i<m; i++) {
		if(!a[0][i]) dfs(0, i);
		if(!a[n-1][i]) dfs(n - 1, i);
	}
	for(int i=0; i<n; i++) {
		if(!a[i][0]) dfs(i, 0);
		if(!a[i][m-1]) dfs(i, m - 1);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			int cnt = 0;
			if(a[i][j] == 1) {
				if(i % 2 == 1) for(int k=0; k<6; k++) if(get(i + dx[k], j + dy[k]) == -1 || get(i + dx[k], j + dy[k]) == 2) cnt++;
				else for(int k=0; k<6; k++) if(get(i + dx2[k], j + dy2[k]) == -1 || get(i + dx2[k], j + dy2[k]) == 2) cnt++;
			}
			ans += cnt;
		}
	}
	printf("%d", ans);
}
