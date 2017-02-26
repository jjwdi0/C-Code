#include <stdio.h>

int dp[10503][503], n, m, a[10005];
int max(int X, int Y){ return X > Y ? X : Y; }

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", a+i);
	for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j] = -1;
	dp[0][0] = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=m; j++) {
			if(~dp[i][j]) {
				if(j < m) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + a[i]);
				if(j) dp[i+j][0] = max(dp[i+j][0], dp[i][j]);
				else dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
			}
		}
	}
	printf("%d", dp[n][0]);
}
