#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

struct seg_tree {
    pr tree[444444];
    int base;
    void init(int x) {for(base = 1; base < x; base <<= 1);}
    void update(int x, int y) {
        x += base - 1;
        tree[x] = pr(y, y);
        x >>= 1;
        while(x) {
            tree[x] = minmax({tree[x*2].first, tree[x*2].second, tree[x*2+1].first, tree[x*2+1].second});
            x >>= 1;
        }
    }
    pr RMMQ(int s, int e) {
        s += base - 1, e += base - 1;
        pr res = tree[e];
        while(s < e) {
            if(s & 1) res = minmax({res.first, res.second, tree[s].first, tree[s].second}), s++;
            if(!(e & 1)) res = minmax({res.first, res.second, tree[e].first, tree[e].second}), e--;
            s >>= 1, e >>= 1;
        }
        if(s == e) res = minmax({res.first, res.second, tree[s].first, tree[e].second});
        return res;
    }
}S;

int T, N, Q, A[100005];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &Q);
        S.init(N);
        for(int i=1; i<=N; i++) S.update(i, A[i] = i);
        while(Q--) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            y++, z++;
            if(x == 1) puts(S.RMMQ(y, z) == pr(y, z) ? "YES" : "NO");
            else S.update(y, A[z]), S.update(z, A[y]), swap(A[y], A[z]);
        }
    }
}

