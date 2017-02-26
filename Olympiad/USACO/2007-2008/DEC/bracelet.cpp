#include <stdio.h>
#define INF 987654321

int dp[2][13000], n, w, a[3500][2];
int max(int X, int Y){ return X < Y ? Y : X; }

int main() {
	scanf("%d %d", &n, &w);
	for(int i=0; i<n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
	for(int i=0; i<2; i++) for(int j=0; j<=w; j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=w; j++) {
			if(dp[i&1][j] != -INF) {
				dp[!(i&1)][j] = max(dp[!(i&1)][j], dp[i&1][j]);
				if(j + a[i][0] > w) continue;
				dp[!(i&1)][j+a[i][0]] = max(dp[!(i&1)][j+a[i][0]], dp[i&1][j] + a[i][1]);
			}
		}
	}
	int ans = 0;
	for(int i=0; i<=w; i++) ans = max(ans, dp[n%2][i]);
	printf("%d", ans);
}
