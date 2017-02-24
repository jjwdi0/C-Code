#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

int N, Q, A[100005]={(int)1e9};

struct seg_tree {
	int tree[444444], base;
	void init(int x) {for(base=1; base<x; base<<=1);}
	void update(int x, int y) {
		x += base - 1;
		tree[x] = y;
		x >>= 1;
		while(x) {
			tree[x] = min(pr(A[tree[x*2]], tree[x*2]), pr(A[tree[x*2+1]], tree[x*2+1])).second;
			x >>= 1;
		}
	}
	int RMQ(int s, int e) {
		s += base - 1, e += base - 1;
		int res = 0;
		while(s < e) {
			if(s & 1) res = min(pr(A[res], res), pr(A[tree[s]], tree[s])).second, s++;
			if(!(e & 1)) res = min(pr(A[res], res), pr(A[tree[e]], tree[e])).second, e--;
			s >>= 1, e >>= 1;
		}
		if(s == e) res = min(pr(A[res], res), pr(A[tree[s]], tree[s])).second;
		return A[res];
	}
}S;

int main() {
	scanf("%d", &N);
	S.init(N);
	for(int i=1; i<=N; i++) scanf("%d", A+i), S.update(i, i);
	for(scanf("%d", &Q); Q--;) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(x == 1) A[y] = z, S.update(y, y);
		else printf("%d\n", S.RMQ(y, z));
	}
}

