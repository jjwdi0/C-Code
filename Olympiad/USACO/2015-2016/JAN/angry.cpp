#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A[103], ans;

int f(int dir, int x, int r) {
	int i = x, res = 0;
	if(dir) {
		while(A[i] - A[x] <= r && i <= N) res++, i++;
		i--;
	}
	else {
		while(A[x] - A[i] <= r && i) res++, i--;
		i++;
	}
	return i == x ? res : res + f(dir, i, r + 1) - 1;
}

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", A+i);
	sort(A+1, A+N+1);
	for(int i=1; i<=N; i++) {
		int u = f(0, i, 1), v = f(1, i, 1);
		ans = max(u + v - 1, ans);
	}
	printf("%d", ans);
}
