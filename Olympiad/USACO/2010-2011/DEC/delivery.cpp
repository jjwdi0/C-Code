#include <bits/stdc++.h>
#define INF 2087654321
using namespace std;
typedef pair<int, int> pr;

int V, E, s, t1, t2;
vector<pr> v[100005];
int dist[100008];

int dijkstra(int S, int E) {
	priority_queue<pr, vector<pr>, greater<pr>> q;
	for(int i=0; i<=V; i++) dist[i] = INF;
	q.push({0, S});
	while(!q.empty()) {
		pr t = q.top(); q.pop();
		if(dist[t.second] < t.first) continue;
		dist[t.second] = t.first;
		if(t.second == E) return t.first;
		for(auto it : v[t.second]) {
			int u = it.first, cost = it.second;
			if(dist[u] > dist[t.second] + cost) dist[u] = dist[t.second] + cost, q.push({dist[u], u});
		}
	}
	return INF;
}

int main() {
	scanf("%d %d %d %d %d", &E, &V, &s, &t1, &t2);
	for(int i=0, x, y, z; i<E; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back({y, z});
		v[y].push_back({x, z});
	}
	int ans = min(dijkstra(s, t1) + dijkstra(t1, t2), dijkstra(s, t2) + dijkstra(t2, t1));
	printf("%d", ans > INF ? -1 : ans);
}
