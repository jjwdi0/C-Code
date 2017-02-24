#include <bits/stdc++.h>
using namespace std;

struct food {
    int c1, c2;
    bool operator < (const food &x) const {
        return c2 < x.c2;
    }
}A[500003];

int N, res;
int mn[500003];
long long ans;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d %d", &A[i].c1, &A[i].c2);
    A[0].c2 = -1e9, A[0].c1 = 1e9;
    sort(A + 1, A + 1 + N);
    mn[N + 1] = 2e9;
    for(int i=N; i; i--) mn[i] = min(A[i].c1, mn[i + 1]);
    for(int i=1; i<=N; i++) {
        if(A[res].c2 - A[res].c1 < A[i].c2 - A[i].c1) res = i;
        ans += (long long)A[i].c2;
        printf("%lld\n", min(ans - A[res].c2 + A[res].c1, ans - A[i].c2 + mn[i]));
    }
}

