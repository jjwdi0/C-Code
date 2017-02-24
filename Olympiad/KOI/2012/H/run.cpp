#include <stdio.h>
#include <algorithm>
#define MAX 1<<23
using namespace std;
typedef pair<int, int> pr;

pr T[500005];
int N, tree[MAX], k;
bool cmp(const pr &x, const pr &y) { return x.second < y.second; }

int init() {
	int temp = 1;
	while(temp < n)
	temp <<= 1;
	return temp;
}

void update(int x) {
	tree[x]++;
	if(x == 1) return;
	update(x / 2);
}

int Q(int x, int y) {
	int m = 0;
	while(x < y) {
		if(x & 1) m+=tree[x++];
		if(!(y & 1)) m += tree[y--];
		x >>= 1, y >>= 1;
	}
	if(x == y) m += tree[x];
	return m;
}

int main() {
	scanf("%d", &N);
	for(int i=0, x; i<N; i++) {
		scanf("%d", &x);
		T[i] = pr(x, i);
	}
	sort(T, T+N);
	for(int i=0; i<N; i++) T[i].first = i + 1;
	sort(T, T+N, cmp);
	k = init();
	for(int i=0; i<N; i++) {
		update(k + T[i].first - 1);
		printf("%d\n", Q(k + T[i].first, k * 2 - 1) + 1);
	}
}
