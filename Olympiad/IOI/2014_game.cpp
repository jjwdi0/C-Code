#include "game.h"
 
int N, lim;
int A[1503][1503], cnt[2049];
 
int LCA(int u, int v) {
    u += lim, v += lim;
    while(u != v) u >>= 1, v >>= 1;
    return u;
}
 
void initialize(int n) {
    N = n;
    for(lim=1; lim<N; lim<<=1);
    for(int i=0; i<N; i++) for(int j=i+1; j<N; j++) {
        A[i][j] = A[j][i] = LCA(i, j);
        cnt[A[i][j]]++;
    }
}
 
int hasEdge(int u, int v) {
    return --cnt[A[u][v]] ? 0 : 1;
}
