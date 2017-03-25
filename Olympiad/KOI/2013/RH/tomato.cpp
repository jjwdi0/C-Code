#include <stdio.h>
#include <queue>
using namespace std;

struct data{ int date, xpos, ypos; } p;
queue <data> q;
int A[1013][1013], N, M, t;

int main() {
    scanf("%d %d", &M, &N);
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
		scanf("%d", &A[i][j]);
        if(A[i][j] == 1) q.push({0, i, j});
	}
    while(!q.empty()) {
		p = q.front(); q.pop();
        if(p.xpos * p.ypos == 0 || p.xpos > N || p.ypos > M) continue;
        if(A[p.xpos-1][p.ypos] == 0) { A[p.xpos-1][p.ypos] = 1; q.push({p.date + 1, p.xpos - 1, p.ypos}); }
        if(A[p.xpos+1][p.ypos] == 0) { A[p.xpos+1][p.ypos] = 1; q.push({p.date + 1, p.xpos + 1, p.ypos}); }
        if(A[p.xpos][p.ypos-1] == 0) { A[p.xpos][p.ypos-1] = 1; q.push({p.date + 1, p.xpos, p.ypos - 1}); }
        if(A[p.xpos][p.ypos+1] == 0) { A[p.xpos][p.ypos+1] = 1; q.push({p.date + 1, p.xpos, p.ypos + 1}); }
        t = p.date;
	}
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) if(A[i][j] == 0) return puts("-1"), 0;
    printf("%d", t);
}
