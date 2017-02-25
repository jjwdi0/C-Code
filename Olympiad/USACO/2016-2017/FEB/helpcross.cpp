#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

int N, M, A[20005];
pr T[20005];
multiset<int> s;

int f(pr x) {
    return upper_bound(A, A+N, x.second) - lower_bound(A, A+N, x.first);
}

bool cmp(const pr &x, const pr &y) {
    return x.second == y.second ? x.first < y.first : x.second < y.second;
}

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%d", A+i), s.insert(A[i]);
    for(int i=0; i<M; i++) scanf("%d %d", &T[i].first, &T[i].second);
    sort(A, A+N);
    sort(T, T+M, cmp);
    int ans = 0;
    for(int i=0; i<M; i++) {
        auto it = s.lower_bound(T[i].first);
        if(it == s.end()) continue;
        if(*it <= T[i].second) {
            ans++;
            s.erase(s.find(*it));
        }
    }
    printf("%d\n", ans);
}
