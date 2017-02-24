#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int tree[100005], base;
    void init(int x) { base = x + 2; }
    void add(int x, int y) {
        x += 2;
        while(x <= base) tree[x] += y, x += x & -x;
    }
    int q(int x) {
        x += 2;
        int res = 0;
        while(x) res += tree[x], x -= x & -x;
        return res;
    }
}bit;

int N, A[100005], B[100005];
long long ans;

int main() {
    scanf("%d", &N);
    bit.init(N);
    for(int i=1, x; i<=N; ++i) scanf("%d", &x), B[x] = i;
    for(int i=1, x; i<=N; i++) scanf("%d", &x), A[B[x]] = i;
    for(int i=1; i<=N; ++i) ans += (long long)(bit.q(N) - bit.q(A[i])), bit.add(A[i], 1);
    puts(ans & 1 ? "Impossible" : "Possible");
}

