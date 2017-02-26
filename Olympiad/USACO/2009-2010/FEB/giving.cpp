#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

int V, E, Q, dist[50005];
priority_queue<pr, vector<pr>, greater<pr>> pq;
vector<pr> v[50005];

int main() {
	scanf("%d %d %d", &V, &E, &Q);
	for(int i=0, x, y, z; i<E; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	for(int i=1; i<=V; i++) dist[i] = 1e9;
	pq.push(make_pair(0, 1));
	while(!pq.empty()) {
		int u = pq.top().second, cost = pq.top().first; pq.pop();
		if(dist[u] < cost) continue;
		dist[u] = cost;
		for(auto it : v[u]) {
			if(dist[it.first] <= it.second + cost) continue;
			dist[it.first] = it.second + cost;
			pq.push(make_pair(dist[it.first], it.first));
		}
	}
	while(Q--) { int x, y; scanf("%d %d", &x, &y); printf("%d\n", dist[x] + dist[y]); }
}
