#include <stdio.h>
#define INF 987654321

int a[103][103], b[103][103], n, m, cnt, cnt2;

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) a[i][j] = b[i][j] = INF;
	for(int i=0, x, y; i<m; i++) {
		scanf("%d %d", &x, &y);
		a[x][y] = b[y][x] = 1;
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) {
		if(a[j][k] > a[j][i] + a[i][k]) a[j][k] = a[j][i] + a[i][k];
		if(b[j][k] > b[j][i] + b[i][k]) b[j][k] = b[j][i] + b[i][k];
	}
	for(int i=1; i<=n; i++) {
		cnt = 0;
		for(int j=1; j<=n; j++) if(a[i][j] < INF) cnt++;
		for(int j=1; j<=n; j++) if(b[i][j] < INF) cnt++;
		if(cnt == n - 1) cnt2++;
	}
	printf("%d", cnt2);
}
