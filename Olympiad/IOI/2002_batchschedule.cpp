#include <stdio.h>
#include <algorithm>
#include <vector>
#define sz(x) ((int)(x).size())
using namespace std;
typedef pair<int, int> pr;
// Optimized O(N) Dynamic Programming Solution (by Convex Hull Trick)
struct CHT{
	vector<pr> v;
	int ind;
	double cross(pr X, pr Y){return (double)(X.second - Y.second) / (Y.first - X.first);}
	void push(int x, int y) {
		while(sz(v) >= 2 && cross(v[sz(v)-2], v[sz(v)-1]) > cross(v[sz(v)-1], {x, y})) v.pop_back();
		v.push_back({x, y});
	}
	int q(double x) {
		while(ind < sz(v) - 1 && cross(v[ind], v[ind+1]) <= x) ind++;
		return v[ind].first * x + v[ind].second;
	}
}cht;
int N, S, S1[10003], S2[10003], D[10003], T[10003];

int main() {
	scanf("%d %d", &N, &S);
	for(int i=1; i<=N; i++) scanf("%d %d", S1+i, S2+i), S1[i] += S1[i-1];
	for(int i=N; i>=0; i--) S2[i] += S2[i+1];
	for(int i=1; i<=N; i++) {
		cht.push(S2[i], D[i-1] + (S - S1[i-1]) * S2[i]);
		D[i] = cht.q(S1[i]);
	}
	printf("%d", D[N]);
}
