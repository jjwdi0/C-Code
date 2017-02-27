#include <bits/stdc++.h>
using namespace std;

int N, M, A[11][11], ans = -1;

bool sq(int x) {return (int)sqrt(x) * (int)sqrt(x) == x;}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%1d", &A[i][j]);
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) for(int x=1; x<=N; x++) for(int y=1; y<=M; y++) {
		int dx = x - i, dy = y - j;
		int cx = i, cy = j, cur = 0;
		while(cx > 0 && cy > 0 && cx <= N && cy <= M) {
			cur = cur * 10 + A[cx][cy];
			if(sq(cur)) ans = max(ans, cur);
			if(!dx && !dy) break;
			cx += dx, cy += dy;
		}
	}
	printf("%d\n", ans);
}
