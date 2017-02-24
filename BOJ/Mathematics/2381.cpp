#include <bits/stdc++.h>
using namespace std;

int N, A[50005][2];
int mx, mn, ans;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]);
    mn = 1e9;
    for(int i=0; i<N; i++) mx = max(mx, A[i][0] + A[i][1]), mn = min(mn, A[i][0] + A[i][1]);
    ans = max(ans, mx - mn);
    mx = -1e9, mn = 1e9;
    for(int i=0; i<N; i++) mx = max(mx, A[i][0] - A[i][1]), mn = min(mn, A[i][0] - A[i][1]);
    ans = max(ans, mx - mn);
    printf("%d\n", ans);
}

