#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define pb push_back
using namespace std;
typedef long long ll;

struct GOLD {
	int x, y;
	ll w;
}A[3005];

struct NODE {
	ll maxsum, sum, Lsum, Rsum;
	NODE() {maxsum = sum = Lsum = Rsum = 0LL;}
	NODE(ll _m, ll _s, ll _L, ll _R) {maxsum = _m, sum = _s, Lsum = _L, Rsum = _R;}
	bool operator == (const NODE &x) const {
		return maxsum == x.maxsum && sum == x.sum && Lsum == x.Lsum && Rsum == x.Rsum;
	}
};

struct seg_tree {
	NODE tree[11111];
	int base;
	void init(int x) {for(base=1; base<x; base<<=1);}
	NODE max_tree(NODE A, NODE B) {
		NODE res = NODE();
		res.maxsum = max({A.maxsum, B.maxsum, A.Rsum + B.Lsum});
		res.Rsum = max(B.Rsum, A.Rsum + B.sum);
		res.Lsum = max(A.Lsum, A.sum + B.Lsum);
		res.sum = A.sum + B.sum;
		return res;
	}
	void update(int x, ll y) {
		x += base - 1;
		tree[x] = NODE(y,y,y,y);
		x >>= 1;
		while(x) {
			NODE t = max_tree(tree[x*2], tree[x*2+1]);
			if(tree[x] == t) break;
			tree[x] = t, x >>= 1;
		}
	}
	ll RMSQ(int s, int e) {
		s += base - 1, e += base - 1;
		NODE T[2] = {NODE(), NODE()};
		bool chk[2] = {0,0};
		while(s < e) {
			if(s & 1) {
				if(!chk[0]) chk[0] = 1, T[0] = tree[s];
				else T[0] = max_tree(T[0], tree[s]);
				s++;
			}
			if(!(e & 1)) {
				if(!chk[1]) chk[1] = 1, T[1] = tree[e];
				else T[1] = max_tree(tree[e], T[1]);
				e--;
			}
			s >>= 1, e >>= 1;
		}
		if(s == e) {
			if(!chk[0]) T[0] = max_tree(T[0], tree[s]);
			else T[1] = max_tree(tree[s], T[1]);
		}
		return max({T[0].maxsum, T[1].maxsum, T[0].Rsum + T[1].Lsum});
	}
}S;

int N;
map<int, int> m1, m2;
vector<int> v[3005];
ll land[3005], ans;

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d %d %lld", &A[i].x, &A[i].y, &A[i].w);
		m1[A[i].x] = m2[A[i].y] = 1;
	}
	int C = 1;
	for(auto &it : m1) it.second = C++;
	C = 1;
	for(auto &it : m2) it.second = C++;
	for(int i=1; i<=N; i++) A[i].x = m1[A[i].x], A[i].y = m2[A[i].y];
	for(int i=1; i<=N; i++) v[A[i].x].pb(i);
	for(int i=1; i<=sz(m1); i++) {
		S.init(sz(m2));
		for(int j=1; j<=sz(m2); j++) S.update(j, land[j] = 0LL);
		for(int j=i; j<=sz(m1); j++) {
			for(int k : v[j]) {
				land[A[k].y] += A[k].w;
				S.update(A[k].y, land[A[k].y]);
			}
			ll res = S.RMSQ(1, sz(m2));
			ans = max(ans, res);
		}
	}
	printf("%lld\n", ans);
}
