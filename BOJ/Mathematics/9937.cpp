#include <bits/stdc++.h>
#define MOD 1000000007
#define sz(x) ((int)(x).size())
using namespace std;
typedef pair<int, int> pr;
typedef long long ll;

int N;
ll ans, cnt;
map<pr, int> m;

int gcd(int x, int y) {return y ? gcd(y, x % y) : x;}

ll nC2(int x) {
    if(x < 2) return 0LL;
    return 1LL * x * (x - 1) / 2;
}

int main() {
    scanf("%d", &N);
    for(int i=0, x, y, z, g; i<N; i++) {
        scanf("%d %d %d", &x, &y, &z);
        g = gcd(x, y);
        x /= g, y /= g;
        int cross = i - m[pr(x, y)];
        ans = (ans + nC2(cross) - cnt + nC2(m[pr(x, y)])) % MOD;
        cnt += (ll)m[pr(x, y)]++;
        cnt %= MOD;
    }
    printf("%lld\n", (ans + MOD) % MOD);
}

