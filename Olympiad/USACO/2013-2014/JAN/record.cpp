#include <bits/stdc++.h>
using namespace std;

struct Z {
    int s, e;
}A[153];

int N, D[153][153];

int f(int x, int y) {
    if(A[x].e > A[y].e) return f(y, x);
    if(~D[x][y]) return D[x][y];
    D[x][y] = 0;
    for(int i=0; i<y; i++) if(A[x].e <= A[i].s && i != y) D[x][y] = max(D[x][y], f(i, y) + 1);
    return D[x][y];
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i].s, &A[i].e);
    A[N].s = A[N].e = 0;
    memset(D, -1, sizeof(D));
    printf("%d\n", f(N, N));
}
