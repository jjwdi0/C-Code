#include <stdio.h>
#define MOD 10000

int dp[103][3][4], n, m, pasta[103];

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0, x, y; i<m; i++) {
		scanf("%d %d", &x, &y);
		pasta[x] = y;
	}
	for(int i=1; i<=3; i++) {
		if(pasta[1]) {
			if(i == pasta[1]) dp[1][1][i] = 1;
		}
		else dp[1][1][i]=1;
	}
	for(int i=1; i<n; i++) {
		if(pasta[i+1]) {
			for(int j=1; j<=3; j++) {
				if(j == pasta[i+1]) dp[i+1][2][j] += dp[i][1][j];
				else dp[i+1][1][pasta[i+1]] += dp[i][1][j] + dp[i][2][j];
			}
		}
		else {
			for(int j=1; j<=3; j++) {
				for(int k=1; k<=3; k++) {
					if(j == k) dp[i+1][2][k] += dp[i][1][j];
					else dp[i+1][1][k] += dp[i][1][j] + dp[i][2][j];
				}
			}
		}
		for(int j=1; j<=2; j++) for(int k=1; k<=3; k++) dp[i+1][j][k] %= MOD;
	}
	int ans = 0;
	for(int i=1; i<=2; i++) for(int j=1; j<=3; j++) ans += dp[n][i][j];
	printf("%d", ans % MOD);
}
