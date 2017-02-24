#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> v, v2;
vector<int> ans;
int N, K, M, cnt, pre;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0, x, y; i<K; i++) {
		scanf("%d %d", &x, &y);
		if(x > y) y += N, M = max(M, y);
		v.push_back({t1, {t2, i + 1}});
	}
	sort(v.begin(), v.end());
	for(int i=1; i<K; i++) if(v[i-1].first != v[i].first) v2.push_back(v[i-1]);
	v2.push_back(v[K-1]);
	for(int i=0; i<v2.size(); i++) {
		if(v2[i].second.first <= M - N || v2[i].second.first <= pre) continue;
		ans.push_back(v2[i].second.second);
		pre = v2[i].second.first;
	}
	sort(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
}
