#include <stdio.h>
int n, m, a[16][16], b[16][16], print[16][16], cmp = 1e9, ans[16][16], dx[4][2]={-1, 0, 1, 0, 0, 1, 0, -1};

bool get(int x, int y){ return x < 0 || y < 0 || x >= n || y >= m; }

void push(int x, int y) {
	b[x][y] = 1 - b[x][y], ans[x][y] = 1;
	for(int i=0; i<4; i++) {
		int px = x + dx[i][0], py = y + dx[i][1];
		if(get(px, py)) continue;
		b[px][py] = 1 - b[px][py];
	}
}

bool chk(int x, int y) {
	if(x == n) {
		bool ret = false;
		for(int i=0; i<n; i++) for(int j=0; j<m; j++) ret |= b[i][j];
		return !ret;
	}
	if(b[x-1][y]) push(x, y);
	return chk(x + (y + 1) / m, (y + 1) % m);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) scanf("%d", &a[i][j]);
	for(int i=0; i<1<<m; i++) {
		for(int j=0; j<n; j++) for(int k=0; k<m; k++) b[j][k] = a[j][k], ans[j][k] = 0;
		int temp = i, cnt = 0;
		while(temp) {
			if(temp & 1) push(0, m - cnt - 1);
			cnt++, temp >>= 1;
		}
		bool res = chk(1, 0);
		if(res) {
			int u = 0;
			for(int j=0; j<n; j++) for(int k=0; k<m; k++) u += ans[j][k];
			if(cmp > u) {
				for(int i=0; i<n; i++) for(int j=0; j<m; j++) print[i][j] = ans[i][j];
				cmp = u;
			}
		}
	}
	if(cmp > 1e8) return puts("IMPOSSIBLE"),0;
	for(int i=0; i<n; puts(""), i++) for(int j=0; j<m; j++) printf("%d ", print[i][j]);
}
