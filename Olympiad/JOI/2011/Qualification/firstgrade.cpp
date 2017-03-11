#include <stdio.h>
typedef long long ll;

ll D[103][21], N, A[103];

ll f(ll x, ll y) {
	if(y<0 || y>20) return 0;
	if(D[x][y] + 1) return D[x][y];
	if(x == 1) {
		if(y == A[0]) return D[x][y] = 1;
		return D[x][y] = 0;
	}
	return D[x][y] = f(x - 1, y + A[x-1]) + f(x - 1, y - A[x-1]);
}

int main() {
	scanf("%lld", &N);
	for(int i=0; i<N; i++) scanf("%lld", A+i);
	for(int i=0; i<=N; i++) for(int j=0; j<=21; j++) D[i][j] = -1;
	printf("%lld", f(N - 1, A[N - 1]));
}
