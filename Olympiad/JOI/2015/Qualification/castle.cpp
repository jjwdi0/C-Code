#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, d[8][2]={-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1}, ans;
char A[1003][1003], B[1003][1003];
queue<pair<int, pair<int, int>>> q;

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) {
		scanf("%s", A[i] + 1);
		for(int j=1; j<=M; j++) if(A[i][j] == '.') q.push({0, {i, j}});
	}
	while(!q.empty()) {
		int cnt = q.front().first, x = q.front().second.first, y = q.front().second.second; q.pop();
		ans = max(ans, cnt);
		for(int i=0; i<8; i++) {
			int xx = x + d[i][0], yy = y + d[i][1];
			if(A[xx][yy] != '.' && A[xx][yy]) A[xx][yy]--;
			if(A[xx][yy] == '0') q.push({cnt + 1, {xx, yy}}), A[xx][yy] = '.';
		}
	}
	printf("%d", ans);
}
