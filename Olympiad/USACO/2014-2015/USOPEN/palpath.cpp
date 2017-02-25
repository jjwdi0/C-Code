#include <stdio.h>
#include <algorithm>
#define MOD 1000000007
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;

char A[503][503];
int N;
ll D[2][503][503];

char get(int x, int y) {
	if(x < 0 || y < 0 || x >= N || y >= N) return '?';
	return A[x][y];
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", A[i]);
	if(A[0][0] == A[N-1][N-1]) D[0][0][0] = 1LL;
	for(int i=0; i<N-1; i++) for(int j=0; j<=i; j++) for(int k=0; k<=i; k++) if(D[i%2][j][k]) {
		if(D[i%2][j][k] >= MOD) D[i%2][j][k] %= MOD;
		pr t1 = pr(j, i - j);
		pr t2 = pr(n - 1 - k, n - 1 - i + k);
		if(get(t1.X + 1, t1.Y) == get(t2.X - 1, t2.Y)) D[!(i&1)][j+1][k+1] += D[i%2][j][k];
		if(get(t1.X + 1, t1.Y) == get(t2.X, t2.Y - 1)) D[!(i&1)][j+1][k] += D[i%2][j][k];
		if(get(t1.X, t1.Y + 1) == get(t2.X - 1, t2.Y)) D[!(i&1)][j][k+1] += D[i%2][j][k];
		if(get(t1.X, t1.Y + 1) == get(t2.X, t2.Y - 1)) D[!(i&1)][j][k] += D[i%2][j][k];
		D[i%2][j][k] = 0LL;
	}
	ll ans = 0LL;
	for(int i=0; i<N; i++) {
		ans += D[!(n%2)][i][N-1-i];
		if(ans >= MOD) ans %= MOD;
	}
	printf("%lld\n", ans);
}
