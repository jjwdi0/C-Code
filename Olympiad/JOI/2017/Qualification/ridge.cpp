#include <bits/stdc++.h>
using namespace std;
typedef pair<bool, int> pr;

int N, M, A[1003][1003], d[4] = { 0, 0, 1, -1 }, ans;
pr D[1003][1003];

pr f(int x, int y) {
    if(D[x][y].second) return D[x][y];
    for(int i=0; i<4; i++) {
        int xx = x + d[i], yy = y + d[3-i];
        if(!xx || !yy || xx > N || yy > M || A[xx][yy] > A[x][y]) continue;
        pr res = f(xx, yy);
        if(res.first) return D[x][y] = res;
        if(!D[x][y].second) D[x][y].second = res.second;
        else if(D[x][y].second != res.second) return D[x][y] = pr(true, D[x][y].second);
    }
    if(!D[x][y].second) D[x][y] = pr(0, A[x][y]);
    return D[x][y];
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) scanf("%d", &A[i][j]);
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) D[i][j] = f(i, j), ans += D[i][j].first;
    printf("%d\n", ans);
}

