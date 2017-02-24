#include <bits/stdc++.h>
using namespace std;

int match_a[303], match_b[303], N, M;
bool adj[303][303], visited[303];

bool dfs(int x) {
	if(visited[x]) return false;
	visited[x] = true;
	for(int i=1; i<=M; i++) {
		if(adj[x][i]) {
			if(match_b[i] == -1 || dfs(match_b[i])) {
				match_a[x] = i, match_b[i] = x;
				return true;
			}
		}
	}
	return false;
}

int bipartite_matching() {
	for(int i=0; i<=300; i++) match_a[i] = match_b[i] = -1;
	int res = 0;
	for(int i=1; i<=N; i++) {
		for(int j=0; j<=300; j++) visited[j] = 0;
		if(dfs(i)) res++;
	}
	return res;
}

int input(int x) {
	for(int i=0; i<=300; i++) for(int j=0; j<=300; j++) adj[i][j] = 0;
	for(int i=0, u, v; i<x; i++) {
		scanf("%d %d", &u, &v);
		adj[u][v] = 1;
	}
	int res = bipartite_matching();
	return res;
}

int main() {
	scanf("%d %d", &N, &M);
	int K1, K2;
	scanf("%d %d", &K1, &K2);
	puts(input(K1) < input(K2) ? "네 다음 힐딱이" : "그만 알아보자");
}