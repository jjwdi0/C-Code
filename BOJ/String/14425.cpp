#include <bits/stdc++.h>
#define MOD ((1LL<<41)-1LL)
using namespace std;
typedef long long ll;

unordered_set<ll> s;
int N, M, ans;
char A[503];

ll get_hash() {
	scanf("%s", A);
	int len = strlen(A);
	ll hv = 0LL;
	for(int j=0; j<len; j++) hv = (hv * 27 + A[j] - 'a' + 1LL) % MOD;
	return hv;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) s.insert(get_hash());
	for(int i=0; i<M; i++) ans += (s.find(get_hash()) != s.end());
	printf("%d\n", ans);
}
