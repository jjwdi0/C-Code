#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N, A[103], B[103];
bool visited[103];

int dfs(int x) {
	visited[x] = true;
	for(int i=1; i<=N; i++) if(!visited[i] && A[x] == B[i]) return dfs(i) + 1;
	return 0;
}
int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", A+i);
	for(int i=1; i<=N; i++) scanf("%d", B+i);
	for(int i=1; i<=N; i++) if(!visited[i]){ int t = dfs(i); if(t) v.push_back(t); }
	sort(v.begin(), v.end());
	printf("%d %d", v.size(), (int)v.size() == 0 ? -1 : v[v.size() - 1] + 1);
}
