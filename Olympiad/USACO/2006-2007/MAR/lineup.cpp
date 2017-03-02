#include <bits/stdc++.h>
#define LIM 1000000
using namespace std;

struct Z {
    int h, x;
    bool operator < (const Z &A) const { return x < A.x; }
}A[1000005];

int N, mx[2000005], ans;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i].h, &A[i].x);
    A[N].x = 1e9;
    sort(A, A+N);
    for(int i=0, cnt=0; i<N; i++) {
        cnt += (A[i].h == 0 ? 1 : -1);
        mx[cnt + LIM] = max(mx[cnt + LIM], A[i].x);
    }
    for(int i=0, cnt=0; i<N; i++) {
        cnt += (A[i].h == 0 ? 1 : -1);
        ans = max(ans, mx[cnt + LIM] - A[i+1].x);
    }
    printf("%d\n", ans);
}
