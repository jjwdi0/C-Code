#include <stdio.h>
#include <algorithm>
using namespace std;

struct data{ int x, y; };

data t[10005];
int par[10005], n, milk[10005];

bool cmp(const data &a, const data &b) { return a.x > b.x; }

int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void uni(int x, int y) {
	x = find(x); y = find(y);
	if(x < y) par[y] = x;
	else par[x] = y;
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d %d", &t[i].x, &t[i].y);
	for(int i=0; i<10005; i++) par[i] = i;
	sort(t, t+n, cmp);
	for(int i=0; i<n; i++) {
		if(find(t[i].y) == 0) continue;
		milk[find(t[i].y)] = t[i].x;
		uni(find(t[i].y), find(t[i].y) - 1);
	}
	int cnt = 0;
	for(int i=0; i<10005; i++) cnt += milk[i];
	printf("%d", cnt);
}
