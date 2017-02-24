#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

vector<pair<int, int>>v[10005];
queue<pair<int, int>> q;
int n, m, s, e, bfs[10005];

bool chk(int x) {
	while(!q.empty()) q.pop();
	q.push({s, 0});
	while(!q.empty()) {
		int temp1 = q.front().first, temp2 = q.front().second; q.pop();
		int size = v[temp1].size();
		if(bfs[temp1] <= temp2) continue;
		bfs[temp1] = temp2;
		if(temp1 == e) return true;
		for(int i=0; i<size; i++) {
			if(v[temp1][i].second < x) continue;
			if(v[temp1][i].second > temp2) q.push({v[temp1][i].first, v[temp1][i].second});
			else q.push({v[temp1][i].first, temp2});
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		v[t1].push_back({t2, t3});
		v[t2].push_back({t1, t3});
	}
	scanf("%d %d", &s, &e);
	int left = 1, right = 1e9;
	while(left <= right) {
		for(int i=0; i<=n; i++) bfs[i]=2e9;
		int mid = (left + right) / 2;
		if(chk(mid)) left = mid + 1;
		else right = mid - 1;
	}
	printf("%d", left - 1);
}
