#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

pair<int, int> mecho;
queue<pair<int, pair<int, int>>> q;
char A[803][803];
int N, M, B[803][803], C[803][803], dx[4][2]={0, 1, 0, -1, 1, 0, -1, 0};

int get(int x, int y) {
	if(x < 0 || y < 0 || x >= N || y >= N || A[x][y] == 'T' || A[x][y] == 'D') return -INF;
	return B[x][y];
}

int get2(int x, int y) {
	if(x < 0 || y < 0 || x >= N || y >= N || A[x][y] == 'T' || A[x][y] == 'H') return -INF;
	return C[x][y];
}

bool chk(int x) {
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) C[i][j] = INF;
	queue<pair<int, pair<int, int>>> bq;
	if(x >= B[mecho.first][mecho.second]) return false;
	bq.push({x * M, {mecho.first, mecho.second}});
	while(!bq.empty()) {
		pair<int, pair<int, int>> t = bq.front(); bq.pop();
		if(C[t.second.first][t.second.second] <= t.first) continue;
		if(A[t.second.first][t.second.second] == 'D') return true;
		C[t.second.first][t.second.second] = t.first / M;
		for(int i=0; i<4; i++) {
			if(get2(t.second.first + dx[i][0], t.second.second + dx[i][1]) <= t.first) continue;
			if(B[t.second.first + dx[i][0]][t.second.second + dx[i][1]] <= (t.first + 1) / M) continue;
			bq.push({t.first + 1, {t.second.first + dx[i][0], t.second.second + dx[i][1]}});
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
		B[i][j] = INF;
		if(A[i][j] == 'M') mecho = {i, j};
		if(A[i][j] == 'H') q.push({0, {i, j}});
	}
	int p = 0;
	while(!q.empty()) {
		pair<int, pair<int, int>> t = q.front(); q.pop();
		if(B[t.second.first][t.second.second] <= t.first)continue;
		B[t.second.first][t.second.second] = t.first;
		for(int i=0; i<4; i++) {
			if(get(t.second.first + dx[i][0], t.second.second + dx[i][1]) == -INF) continue;
			q.push({t.first + 1, {t.second.first + dx[i][0], t.second.second + dx[i][1]}});
		}
		p = max(p, t.first);
	}
	int lo = 0, hi = p;
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(chk(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	printf("%d", lo - 1);
}
