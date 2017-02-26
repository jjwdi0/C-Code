#include <stdio.h>
#include <algorithm>
using namespace std;

struct cow{
	int s, e, rank;
}t[100005];

int n, k;
bool cmp(const cow &x, const cow &y) { return x.s < y.s; }
bool cmp2(const cow &x, const cow &y) { return x.e < y.e; }

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d %d", &t[i].s, &t[i].e);
	sort(t, t+n, cmp);
	for(int i=0; i<n; i++) t[i].rank = i + 1;
	sort(t, t+n, cmp2);
	int m = 0, ans = 0;
	for(int i=0; i<n; i++) {
		if(i == m && m + 1 == t[i].rank) ans++;
		m = max(m, t[i].rank);
	}
	printf("%d\n", ans);
}
