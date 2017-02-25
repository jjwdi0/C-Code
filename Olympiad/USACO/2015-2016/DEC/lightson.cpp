#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, dx[4][2]={1, 0, -1, 0, 0, 1, 0, -1};
vector<pair<int, int>> v[10005];
bool chk[103][103], l[103][103], visited[103][103];
queue<pair<int, int>> q;

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0, a, b, x, y; i<m; i++) {
		scanf("%d %d %d %d", &a, &b, &x, &y);
		v[(a-1)*n+b].push_back({x, y});
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) chk[i][j] = 0, l[i][j] = 0;
	chk[1][1] = 1, l[1][1] = 1;
	q.push({1, 1});
	while(!q.empty()) {
		pair<int, int> T = q.front();q.pop();
		if(visited[T.first][T.second] || T.first <= 0 || T.second <= 0 || T.first > n || T.second > n) continue;
		visited[T.first][T.second] = 1;
		for(auto it : v[(T.first - 1) * n + T.second]) {
			l[it.first][it.second] = 1;
			if(chk[it.first][it.second]) continue;
			for(int i=0; i<4; i++) if(chk[it.first+dx[i][0]][it.second+dx[i][1]]) chk[it.first][it.second] = 1;
			if(chk[it.first][it.second]) q.push({it.first, it.second});
		}
		for(int i=0; i<4; i++) if(l[T.first+dx[i][0]][T.second+dx[i][1]]) chk[T.first+dx[i][0]][T.second+dx[i][1]] = 1, q.push({T.first+dx[i][0], T.second+dx[i][1]});
	}
	int ans = 0;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(l[i][j]) ans++;
	printf("%d", ans);
}
