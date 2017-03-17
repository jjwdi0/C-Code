#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// TLE on 4 testcases, result : *********t*ttt*
// time complexity : O(N^1.5 log N)

int SQRT;

struct BIT {
    int tree[100005], base;
    void init(int x) { base = x + 2; }
    void add(int x, int y) {
        x += 2;
        while(x <= base) tree[x] += y, x += x & -x;
    }
    int q(int x) {
        int res = 0;
        x += 2;
        while(x) res += tree[x], x -= x & -x;
        return res;
    }
}bit;

struct query {
    int s, e, num, ti;
    bool operator < (const query &A) const { return s / SQRT == A.s / SQRT ? e < A.e : s < A.s; }
}T[100005];

int N, K, A[200005], chk[200005], on;
ll ans;

void f(int x, int y) {
    if(chk[x] == 2) bit.add(x, -1), on--;
    chk[x] += y;
    if(chk[x] == 2) bit.add(x, 1), on++;
}

int main() {
    freopen("friendcross.in", "r", stdin);
    freopen("friendcross.out", "w", stdout);
    scanf("%d %d", &N, &K);
    SQRT = (int)sqrt(N * 2);
    for(int i=1; i<=N*2; i++) scanf("%d", A+i);
    for(int i=1; i<=N*2; i++) {
        if(i <= N) T[A[i]].s = i;
        else T[A[i]].e = i;
    }
    sort(T + 1, T + 1 + N);
    bit.init(N);
    int s = 1, e = 0;
    for(int i=1; i<=N; i++) {
        while(T[i].e > e) f(A[++e], 1);
        while(T[i].e < e) f(A[e--], -1);
        while(T[i].s > s) f(A[s++], -1);
        while(T[i].s < s) f(A[--s], 1);
        int u = min(N, A[s] + K);
        int d = max(0, A[s] - K - 1);
        ans += (ll)(on - bit.q(u) + bit.q(d));
    }
    printf("%lld\n", ans);
}
