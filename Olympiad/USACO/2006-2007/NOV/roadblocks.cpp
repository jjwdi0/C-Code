#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef pair<int, int> pr;

int V, E, dist[5005][2];
vector<pr> v[5005];
priority_queue<pr, vector<pr>, greater<pr>> pq;

int main() {
	scanf("%d %d", &V, &E);
	for(int i=0, x, y, z; i<E; i++) scanf("%d %d %d", &x, &y, &z), v[x].push_back({y, z}), v[y].push_back({x, z});
	for(int i=1; i<=V; i++) dist[i][0] = dist[i][1] = INF;
	pq.push({0, 1});
	dist[1][0] = 0;
	while(!pq.empty()) {
		int u = pq.top().second, cost = pq.top().first; pq.pop();
		if(dist[u][1] < cost) continue;
		for(auto it : v[u]) {
			int there = it.first, c = it.second;
			if(dist[there][1] <= c + cost) continue;
			if(dist[there][0] > c + cost) dist[there][1] = dist[there][0], dist[there][0] = c + cost;
			else dist[there][1] = c + cost;
			pq.push({c + cost, there});
		}
	}
	printf("%d", dist[V][1]);
}
