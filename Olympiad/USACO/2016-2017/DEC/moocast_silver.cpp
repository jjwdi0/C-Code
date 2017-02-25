#include <stdio.h>
#include <string.h>

int N, A[202][3], ans;
bool v[202][202], visited[202];

int sz(int x){ return x*x; }
int dfs(int x) {
	int res = 1;
	visited[x] = 1;
	for(int i=0; i<N; i++) if(v[x][i] && !visited[i]) res += dfs(i);
	return res;
}
int max(int X, int Y){ return X>Y?X:Y; }

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(sz(A[i][0] - A[j][0]) + sz(A[i][1] - A[j][1]) <= sz(A[i][2])) v[i][j] = 1;
	for(int i=0; i<N; i++) memset(visited, 0, sizeof(visited)), ans = max(ans, dfs(i));
	printf("%d\n", ans);
}
