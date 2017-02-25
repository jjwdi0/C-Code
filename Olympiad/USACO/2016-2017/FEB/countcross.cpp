#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef pair<int, int> pr;

struct Z {
    int x, y, c;
    Z() {x = y = c = 0;}
    Z(int _x, int _y, int _c) {x = _x, y = _y, c = _c;}
    bool operator < (const Z &A) const {
        return c > A.c;
    }
};

int N, M, K, dx[4] = {0, 0, 1, -1};
bool v[103][103][4];
int A[103][103], C[103][2], D[103][103];

priority_queue<Z> q;

int get_BFS(int idx) {
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) D[i][j] = INF;
    q.push(Z(C[idx][0], C[idx][1], 0));
    while(!q.empty()) {
        Z temp = q.top(); q.pop();
        int x = temp.x, y = temp.y, c = temp.c;
        if(D[x][y] < c) continue;
        D[x][y] = c;
        for(int i=0; i<4; i++) {
            int xx = x + dx[i], yy = y + dx[3-i];
            if(!xx || !yy || xx > N || yy > N) continue;
            if(D[xx][yy] <= c + v[x][y][i]) continue;
            D[xx][yy] = c + v[x][y][i];
            q.push(Z(xx, yy, D[xx][yy]));
        }
    }
    int res = 0;
    for(int i=1; i<=M; i++) res += !!D[C[i][0]][C[i][1]];
    return res;
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0, cx, cy, tx, ty; i<K; ++i) {
        scanf("%d %d %d %d", &cx, &cy, &tx, &ty);
        for(int j=0; j<4; j++) {
            if(cx + dx[j] == tx && cy + dx[3-j] == ty) v[cx][cy][j] = 1;
            if(tx + dx[j] == cx && ty + dx[3-j] == cy) v[tx][ty][j] = 1;
        }
    }
    for(int i=1; i<=M; i++) {
        scanf("%d %d", &C[i][0], &C[i][1]);
        A[C[i][0]][C[i][1]] = i;
    }
    int ans = 0;
    for(int i=1; i<=M; i++) ans += get_BFS(i);
    printf("%d\n", ans / 2);
}
