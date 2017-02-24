#include <bits/stdc++.h>
#define MOD ((1LL<<41)-1LL)
using namespace std;
typedef long long ll;

unordered_set<ll> s;
int N, M, ans;
char A[503];

ll get_hash(int x) {
	scanf("%s", A);
	ll hv = 0LL;
	for(int j=0; A[j]; j++) hv = (hv * 27 + A[j] - 'a' + 1LL) % MOD, s.insert(1LL * x * hv);
	return hv;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) s.insert(get_hash(1));
	for(int i=0; i<M; i++) ans += (s.find(get_hash(0)) != s.end());
	printf("%d\n", ans);
}