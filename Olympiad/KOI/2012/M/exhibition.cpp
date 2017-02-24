#include <stdio.h>
#include <algorithm>
#define MAX_N 300005
using namespace std;

pair<int, int> T[MAX_N];
int N, D[MAX_N], C, num[MAX_N];

int main() {
	scanf("%d %d", &N, &C); 
	for(int i=0; i<N; i++) {
		scanf("%d %d", &T[i].first, &T[i].second);
		num[i] = T[i].first;
	}
	int cnt = 0;
	for(int i=0; i<N; i++) if(T[i].first < C) cnt++;
	if(cnt == N) return puts("0"),0;
	sort(T, T+N), sort(num, num + N);
	D[0] = T[0].second;
	for(int i=1; i<N; i++) {
		if(upper_bound(num, num + i, T[i].first - c) - num - 1 < 0) D[i] = max(D[i-1], T[i].second);
		D[i] = max(D[upper_bound(num, num + i, T[i].first - c) - num - 1] + T[i].second, D[i-1]);
	}
	printf("%d", D[n-1]);
}
