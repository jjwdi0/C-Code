#include <stdio.h>
#include <map>
#define INF 987654321
using namespace std;

map<int, int> A, D[2];
int par[20005], test=5, N, M;

int find(int x) {
	if(x==par[x])return x;
	return par[x]=find(par[x]);
}

void uni(int x, int y) {
	x=find(x); y=find(y);
	par[x]=y;
}

int f(int x) { return x > N ? -1 : 1; }
int abs(int x) { return x > 0 ? x : -x; }

int main() {
	while(test--) {
		scanf("%d %d", &N, &M);
		for(int i=1; i<=2*N; i++) par[i] = i;
		A.clear();
		for(int i=0; i<2; i++) D[i].clear();
		bool fin = false;
		for(int i=0, x, y, z; i<M; i++) {
			scanf("%d %d %d", &x, &y, &z);
			if(x > 0) uni(y, z), uni(y + N, z + N);
			else uni(y, z + N); uni(y + N, z);
		}
		for(int i=1; i<=N; i++) {
			if(find(i) == find(i + N)) {
				puts("-1");
				fin=true;
				break;
			}
		}
		if(fin)	continue;
		for(int i=1; i<=N; i++) {
			if(A.find(find(i)) == A.end()) {
				if(A.find(find(i + N)) == A.end()) A[find(i)] = f(i);
				else A[find(i + N)] += f(i + N);
			}
			else A[find(i)] += f(i);
		}
		D[0][0] = 1;
		auto j = A.begin();
		for(int i=0; i<A.size(); i++) {
			D[(i + 1) % 2].clear();
			for(auto it : D[i % 2]) {
				D[(i + 1) % 2][it.first + j -> second] = 1;
				D[(i + 1) % 2][it.first - j -> second] = 1;
			}
			j++;
		}
		int ans = INF;
		for(auto it : D[A.size() % 2]) if(ans > abs(it.first)) ans = abs(it.first);
		printf("%d\n", ans);
	}
}
