#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef pair<int, int> pr;

int T, N, M, W, dist[503];
vector<pr> v[503];

bool bf() {
	bool res = true;
	for(int i=1; i<=N; i++) {
		for(auto it : v[i]) {
			if(dist[it.first] > dist[i] + it.second) {
				dist[it.first] = dist[i] + it.second;
				res = false;
			}
		}
	}
	return res;
}

void init() {
	for(int i=0; i<=500; i++) v[i].clear();
	for(int i=0; i<=500; i++) dist[i] = INF;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d %d %d", &N, &M, &W);
		for(int i=0, x, y, z; i<M; i++) {
			scanf("%d %d %d", &x, &y, &z);
			v[x].push_back({y, z});
			v[y].push_back({x, z});
		}
		for(int i=0, x, y, z; i<W; i++) {
			scanf("%d %d %d", &x, &y, &z);
			v[x].push_back({y, -z});
		}
		dist[1] = 0;
		for(int i=0; i<N; i++) if(bf()) break;
		puts(bf() ? "NO" : "YES");
	}
}
