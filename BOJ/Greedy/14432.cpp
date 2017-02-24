#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define pb push_back
using namespace std;
typedef long long ll;

int N, M, A[100005];
vector<int> v[100005];
ll ans;

void put(int x, int u) {
	A[x] -= u;
	ans += (ll)u;
	for(int i : v[x]) A[i] -= u;
}

void dfs(int x, int par) {
	int res = 0;
	for(int i : v[x]) {
		if(i == par) continue;
		dfs(i, x);
		res = max(res, A[i]);
	}
	put(x, res);
}

int main() {
	scanf("%d %d", &N, &M);
	assert(N == M + 1);
	for(int i=1; i<=N; i++) scanf("%d", A+i);
	for(int i=1, x, y; i<N; i++) {
		scanf("%d %d", &x, &y);
		v[x].pb(y), v[y].pb(x);
	}
	dfs(1, 0);
	return !printf("%lld\n", ans + (ll)max(A[1], 0));
}