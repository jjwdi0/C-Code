#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    bool operator < (const point &A) const { return x < A.x; }
}A[100005];

int N, M, L;
int T[100005];
int ans;
 
int main () {
    scanf("%d %d %d", &M, &N, &L);
    for (int i=0; i<M; i++) scanf("%d", T+i);
    for (int i=0; i<N; i++) scanf("%d %d", &A[i].x, &A[i].y);
    sort(T, T+M);
    sort(A, A+N);
    for(int i=0, j=0; i<N; i++) {
        while(j < M && T[j] < A[i].x) j++;
        bool flag = false;
        if(j > 0 && A[i].x - T[j-1] + A[i].y <= L) flag = true;
        if(j < m && T[j] - A[i].x + A[i].y <= L) flag = true;
        ans += flag;
    }
    printf ("%d\n", ans);
}
