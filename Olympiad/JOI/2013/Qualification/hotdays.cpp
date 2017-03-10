#include <stdio.h>
#define INF -987654321

struct data{ int low, high, cost; };

int dp[203][203], C[203], n, m;
data cloth[203];
int max(int X, int Y) { return X > Y ? X : Y; }
int abs(int x) { return x > 0 ? x : -x; }

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%d", C+i);
		for(int j=0; j<=m; j++) dp[i][j] = dp[i+1][j] = INF;
	}
	for(int i=1; i<=m; i++) scanf("%d %d %d", &cloth[i].low, &cloth[i].high, &cloth[i].cost);
	dp[0][0] = 0;
	for(int i=0; i<n; i++) for(int j=0; j<=m; j++) {
		if(dp[i][j] - INF) {
			for(int k=1; k<=m; k++) {
				if(C[i] >= cloth[k].low && C[i] <= cloth[k].high) {
					dp[i+1][k] = max(dp[i+1][k], dp[i][j] + abs(cloth[j].cost - cloth[k].cost));
					dp[i+1][k] *= !!j;
				}
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=m; i++) ans = max(ans, dp[n][i]);
	printf("%d", ans);
}
