#include <stdio.h>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> pr;

int N, M, xx1, xx2, yy1, yy2, D[103][103][5], dx[4][2]={1, 0, -1, 0, 0, 1, 0, -1};
char A[103][103];
queue<pair<pr, pr>> q;
bool get(int x, int y) { if(x < 0 || y < 0 || x >= N || y >= N || A[x][y] == 'x') return false; return true; }

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
		if(A[i][j] == 'A') xx1 = i, yy1 = j;
		if(A[i][j] == 'B') xx2 = i, yy2 = j;
	}
	for(int i=0; i<=100; i++) for(int j=0; j<=100; j++) for(int k=0; k<5; k++) D[i][j][k] = INF;
	for(int i=0; i<4; i++) q.push({{0, i}, {xx1, yy1}});
	while(!q.empty()) {
		int dir = q.front().first.second, move = q.front().first.first, x = q.front().second.first, y = q.front().second.second; q.pop();
		if(D[x][y][dir] <= move) continue;
		D[x][y][dir] = move;
		for(int i=0; i<4; i++) {
			int xx = x + dx[i][0], yy = y + dx[i][1];
			if(!get(xx, yy)) continue;
			q.push({{move + (i != dir), i}, {xx, yy}});
		}
	}
	printf("%d", min({D[xx2][yy2][0], D[xx2][yy2][1], D[xx2][yy2][2], D[xx2][yy2][3]}));
}
