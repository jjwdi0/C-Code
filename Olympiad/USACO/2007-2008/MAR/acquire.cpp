#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

struct convex_hull_trick {
	vector<pr> v;
	int ind;
	double cross(pr x, pr y) {
		return (double)(y.second - x.second) / (x.first - y.first);
	}
	void push(ll x, ll y) {
		while(sz(v) >= 2 && cross(v[sz(v)-2], v[sz(v)-1]) >= cross(v[sz(v)-1], mp(x, y))) v.pop_back();
		v.pb(mp(x, y));
	}
	ll q(ll x) {
		while(ind + 1 < sz(v) && cross(v[ind], v[ind + 1]) <= x) ind++;
		return v[ind].first * x + v[ind].second;
	}
}cht;

int N;
pr A[50003];
vector<pr> v;
stack<pr> s;

bool cmp(const pr &x, const pr &y) {
	return x.first == y.first ? x.second > y.second : x.first < y.first;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%lld %lld", &A[i].first, &A[i].second);
	}
	sort(A, A+N, cmp);
	for(int i=0; i<N; i++) {
		while(!s.empty() && s.top().second <= A[i].second) s.pop();
		s.push(A[i]);
	}
	while(!s.empty()) {
		v.pb(s.top());
		s.pop();
	}
	reverse(all(v));
	ll ans = 0LL;
	for(auto it : v) {
		cht.push(it.second, ans);
		ans = cht.q(it.first);
	}
	printf("%lld\n", ans);
}
