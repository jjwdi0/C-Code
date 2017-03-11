#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, S, ans, dist[1111][1111], d[4][2]={1, 0, -1, 0, 0, 1, 0, -1};
char A[1111][1111];
queue<pair<int, pair<int, int>>> q;

bool get(int x, int y) { return !(x < 0 || y < 0 || x >= N || y >= M || A[x][y] == 'X'); }
int bfs(int val) {
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) dist[i][j] = INF;
	while(!q.empty()) {
		int cnt = q.front().first, x = q.front().second.first, y = q.front().second.second; q.pop();
		if(dist[x][y] < cnt) continue;
		dist[x][y] = cnt;
		if(A[x][y] == val + '0') {
			while(!q.empty()) q.pop();
			q.push({0, {x, y}});
			return cnt;
		}
		for(int i=0; i<4; i++) {
			int xx = x + d[i][0], yy = y + d[i][1];
			if(get(xx, yy) && dist[xx][yy] == INF) dist[xx][yy] = cnt + 1, q.push({cnt + 1, {xx, yy}});
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &S);
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(A[i][j] == 'S') q.push({0, {i, j}});
	for(int i=1; i<=S; i++) ans += bfs(i);
	printf("%d", ans);
}
