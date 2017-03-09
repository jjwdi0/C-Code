#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

int N, A[3003];
long long D[2][3001*3001/2+3], ans;
bool chk[1111111];

int f(int x, int y) {
	int res = N * (N + 1) / 2 - (N - x) * (N - x + 1) / 2;
	return res + y - x - 1;
}

int g(int x, int y) {
	int v = 2 * A[y] - A[x];
	int res = lower_bound(A + y + 1, A + N + 1, v) - A;
	if(A[res] == v) return res;
	return 987654321;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", A+i+1), chk[A[i+1]] = 1;
	for(int i=1; i<N; i++) for(int j=i+1; j<=N; j++) D[0][f(i, j)] = A[i] + A[j];
	for(int it=0; it<2; it++) for(int i=1; i<N; i++) for(int j=i+1; j<=N; j++) {
		if(!D[it][f(i, j)]) continue;
		if(it == 1) ans = max(ans, D[it][f(i, j)]);
		if(A[j] * 2 - A[i] > 1000000 || !chk[A[j] * 2 - A[i]]) continue;
		int ind = g(i, j);
		D[min(1, it + 1)][f(j, ind)] = max(D[min(1, it + 1)][f(j, ind)], D[it][f(i, j)] + A[ind]);
	}
	printf("%lld\n", ans);
}
