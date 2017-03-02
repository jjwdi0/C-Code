#include <bits/stdc++.h>
#define MOD ((1LL<<37)-1)
using namespace std;
typedef long long ll;

int N, K, cnt[32], ans;
int A[100005];
map<ll, int> m;

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", A+i);
        for(int j=0; j<K; j++) cnt[j] += (A[i] >> j) & 1;
        bool mn = false;
        for(int j=0; j<K; j++) if(cnt[j] == 0) mn = true;
        if(!mn) for(int j=0; j<K; j++) cnt[j]--;
        ll h = 0LL;
        for(int j=0; j<K; j++) h = (h * (ll)(N + 1) + cnt[j]) % MOD;
        m[h] = max(m[h], i + 1);
    }
    for(int i=0; i<K; i++) cnt[i] = 0;
    ans = m[0];
    for(int i=0; i<N; i++) {
        for(int j=0; j<K; j++) cnt[j] += (A[i] >> j) & 1;
        bool mn = false;
        for(int j=0; j<K; j++) if(cnt[j] == 0) mn = true;
        if(!mn) for(int j=0; j<K; j++) cnt[j]--;
        ll h = 0LL;
        for(int j=0; j<K; j++) h = (h * (ll)(N + 1) + cnt[j]) % MOD;
        ans = max(ans, m[h] - i - 1);
    }
    printf("%d\n", ans);
}
