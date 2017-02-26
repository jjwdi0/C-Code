#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
typedef pair<int, int> pr;

vector<pair<int, pair<int, bool>>> v[1003];
priority_queue<pr, vector<pr>, greater<pr>> pq;
int V, E, N, dist[1003], ans[1003];

void init() { for(int i=0; i<=V; i++) dist[i] = INF; }

int main() {
	scanf("%d %d %d", &V, &E, &N);
	for(int i=0, x, y, z; i<E; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back({y, {z, 1}});
		v[y].push_back({x, {z, 0}});
	}
	init();
	pq.push({0, N});
	while(!pq.empty()) {
		pr T = pq.top(); pq.pop();
		int cost = T.first, u = T.second;
		if(dist[u] < cost) continue;
		dist[u] = cost;
		for(auto it : v[u]) {
			if(!it.second.second) continue;
			if(dist[it.first] <= dist[u] + it.second.first) continue;
			dist[it.first] = dist[u] + it.second.first;
			pq.push({dist[it.first], it.first});
		}
	}
	for(int i=1; i<=V; i++) ans[i] = dist[i];
	init();
	pq.push({0, N});
	while(!pq.empty()) {
		pr T = pq.top(); pq.pop();
		int cost = T.first, u = T.second;
		if(dist[u] < cost) continue;
		dist[u] = cost;
		for(auto it : v[u]) {
			if(it.second.second) continue;
			if(dist[it.first] <= dist[u] + it.second.first) continue;
			dist[it.first] = dist[u] + it.second.first;
			pq.push({dist[it.first], it.first});
		}
	}
	int ANS = 0;
	for(int i=1; i<=V; i++) ANS = max(ANS, dist[i] + ans[i]);
	printf("%d", ANS);
}
