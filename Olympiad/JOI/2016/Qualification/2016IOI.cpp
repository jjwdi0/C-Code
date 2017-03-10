#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, dp[53][3], color[53][3];
char flag[53][53];

int f(int x, int y) {
	if(dp[x][y]) return dp[x][y];
	if(x == n - 1) {
		if(y == 2) return 0;
		return 978654321;
	}
	if(y <= 1) return dp[x][y] = min(f(x + 1, y) + m - color[x+1][y], f(x + 1, y + 1) + m - color[x+1][y+1]);
	return dp[x][y] = f(x + 1, y) + m - color[x+1][y];
}

int main() {
	scanf("%d %d\n", &n, &m);
	for(int i=0; i<n; i++) gets(flag[i]);
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
		if(flag[i][j] == 'W') color[i][0]++;
		if(flag[i][j] == 'B') color[i][1]++;
		if(flag[i][j] == 'R') color[i][2]++;
	}
	printf("%d", f(0, 0) + m - color[0][0]);
}
