#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;

// use Kruskal's MST Algorithm
int parent[1005], n, m, cnt;
pair<int, int> pos[1005];
double mid_count;
vector<pair<double, pair<int, int>>> edge;

int find(int x) { return (parent[x] == x) ? x : parent[x] = find(parent[x]); }
void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x > y) swap(x, y);
	parent[y] = x;
}

double get_dist(int x, int y) { return sqrt(((ll)pos[x].first - (ll)pos[y].first) * ((ll)pos[x].first - (ll)pos[y].first) + ((ll)pos[x].second - (ll)pos[y].second) * ((ll)pos[x].second - (ll)pos[y].second)); }

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; parent[i]=i,i++) scanf("%d %d", &pos[i].first, &pos[i].second);
	for(int i=0, x, y; i<m; i++) {
		scanf("%d %d", &x, &y);
		if(find(x) == find(y)) m--, i--;
		else unite(x, y);
	}
	for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) {
		double temp = get_dist(i, j);
		edge.push_back({temp, {i, j}});
	}
	sort(edge.begin(), edge.end());
	int size = edge.size();
	for(int i=0; i<size; i++) {
		if(find(edge[i].second.first) == find(edge[i].second.second)) continue;
		unite(edge[i].second.first, edge[i].second.second);
		mid_count += edge[i].first;
		cnt++;
		if(cnt == n - m - 1) return !printf("%.2f", mid_count);
	}
}
