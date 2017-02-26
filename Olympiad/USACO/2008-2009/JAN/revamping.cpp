#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_N 10005
#define MAX_K 23
#define INF 1987654321
using namespace std;

struct edge{
	int to, cost;
};

struct data{
	int num, cnt, total;
	bool operator < (const data &x) const{
	return x.total<total;
	}
};

int dp[MAX_N][MAX_K], n, m, k;
vector<edge> v[MAX_N];
priority_queue<data> q;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0, x, y, z; i<m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		v[x].push_back({y, z});
		v[y].push_back({x, z});
	}
	for(int i=0; i<=n; i++) for(int j=0; j<=k; j++) dp[i][j] = INF;
	q.push({1, 0, 0});
	while(!q.empty()) {
		data temp = q.top(); q.pop();
		if(dp[temp.num][temp.cnt] <= temp.total) continue;
		dp[temp.num][temp.cnt] = temp.total;
		int size = v[temp.num].size();
		for(int i=0; i<size; i++) {
			if(dp[v[temp.num][i].to][temp.cnt] == INF) q.push({v[temp.num][i].to, temp.cnt, temp.total + v[temp.num][i].cost});
			if(temp.cnt < k && dp[v[temp.num][i].to][temp.cnt+1] == INF) q.push({v[temp.num][i].to, temp.cnt + 1, temp.total});
		}
	}
	int ans = INF;
	for(int i=0; i<=k; i++) ans = min(ans, dp[n][i]);
	printf("%d", ans);
}
