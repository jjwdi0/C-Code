#include <stdio.h>
#include <algorithm>
#include <map>
#define INF ((1LL)<<55)
using namespace std;
typedef long long ll;

int N, iy, fx;
pair<int, pair<int, int>> A[100005];
map<int, ll> m;

void f(int x, int y, ll z) {
	m[y] = min((m[y] == 0 ? INF : m[y]), z + abs(x - y));
}

int main() {
	scanf("%d %d %d", &N, &iy, &fx);
	for(int i=0; i<N; i++) scanf("%d %d %d", &A[i].first, &A[i].second.first, &A[i].second.second);
	sort(A, A+N);
	m[iy] = 0LL;
	for(int i=0; i<N; i++) {
		map<int, ll> cur;
		auto end_it = m.upper_bound(A[i].second.second);
		for(map<int, ll>::iterator it = m.lower_bound(A[i].second.first); it != end_it; it++) {
			int u = it -> first;
			ll v = it -> second;
			cur[u] = v;
		}
		m.erase(m.lower_bound(A[i].second.first), m.upper_bound(A[i].second.second));
		for(auto it : cur) {
			int u = it.first;
			ll v = it.second;
			f(u, A[i].second.first, v);
			f(u, A[i].second.second, v);
		}
	}
	ll ans = INF;
	int cnt = 0;
	for(auto it : m) ans = min(it.second, ans);
	printf("%lld\n", ans + (ll)fx);
	for(auto it : m) if(it.second == ans) cnt++;
	printf("%d ", cnt);
	for(auto it : m) if(it.second == ans) printf("%d ", it.first);
}
