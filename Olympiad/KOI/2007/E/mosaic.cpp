#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> T[1111];
int N, M, W, H;

bool chk(int x) {
	int res = 0;
	for(int i=1; i<=N; res++) {
		int j = i;
		while(T[i].first + x > T[j].first && j <= N) j++;
		i = j;
	}
	return res <= M;
}

int main() {
	scanf("%d %d %d %d", &W, &H, &M, &N);
	int lo = 0, hi = W;
	for(int i=1; i<=N; i++) scanf("%d %d", &T[i].second, &T[i].first), lo = max(lo, T[i].second);
	sort(T + 1, T + N + 1);
	while(lo <= hi) {
		int mid = lo + hi >> 1;
		if(chk(mid)) hi = mid - 1;
		else lo = mid + 1;
	}
	printf("%d", hi + 1);
}
