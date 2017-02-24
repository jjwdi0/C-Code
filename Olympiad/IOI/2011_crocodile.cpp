#include "crocodile.h"
#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int>> v[100003];
int D[100003][2];
bool visited[100003];
 
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]) {
	for(int i=0; i<M; i++) {
		int x = R[i][0], y = R[i][1], z = L[i];
		x++, y++;
		v[x].push_back({y, z});
		v[y].push_back({x, z});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i=0; i<=N; i++) D[i][0] = D[i][1] = 1e9;
	for(int i=0; i<K; i++) D[P[i] + 1][0] = D[P[i] + 1][1] = 0, pq.push({0, P[i] + 1});
	while(!pq.empty()) {
		int cost = pq.top().first, u = pq.top().second; pq.pop();
		if(visited[u]) continue;
		visited[u] = 1;
		for(auto it : v[u]) {
			int c = cost + it.second, ne = it.first;
			if(visited[ne]) continue;
			if(D[ne][0] > c) {
				D[ne][1] = D[ne][0];
				D[ne][0] = c;
				if(D[ne][1] < 1e9) pq.push({D[ne][1], ne});
			}
			else if(D[ne][1] > c) {
				D[ne][1] = c;
				pq.push({c, ne});
			}
		}
	}
	return D[1][1];
}
