#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Z {
    ll x; int d;
    bool operator < (const Z &A) const { return x < A.x; }
}A[100005];

int N, Q;
ll T;
vector<ll> v;

int main() {
    scanf("%d %lld %d", &N, &T, &Q);
    for(int i=1; i<=N; i++) scanf("%lld %d", &A[i].x, &A[i].d);
    sort(A+1, A+N+1);
    for(int i=1; i<=N; i++) if(A[i].d == 2 && A[i-1].d == 1) v.push_back(A[i].x + A[i-1].x >> 1);
    for(int i=0, x; i<Q; i++) {
        ll ub;
        scanf("%d", &x);
        auto it = lower_bound(v.begin(), v.end(), A[x].x);
        if(A[x].d == 1) {
            if(it == v.end()) ub = 8e18;
            else ub = *it;
            printf("%lld\n", min(ub, A[x].x + T));
        }
        else {
            if(it == v.begin()) ub = -8e18;
            else ub = *(--it);
            printf("%lld\n", max(ub, A[x].x - T));
        }
    }
}
