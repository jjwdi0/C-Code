#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n, m, D[23];

int f(int x) {
	if(x == 0) return D[x] = 1;
	if(D[x]) return D[x];
	int t = 0;
	for(int j=0; j<x; j++) if(v[j].first < v[x].first && v[j].second < v[x].second)
	t = max(f(j) + 1, t);
	if(!t) t++;
	return D[x] = t;
}

int main() {
	scanf("%d", &n);
	for(int i=0, x, y; i<n; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++) m = max(f(i), m);
	printf("%d", m);
}
