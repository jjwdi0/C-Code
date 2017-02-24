#include <stdio.h>
typedef long long ll;

int N;
ll A[111111], ans, m = 1111111111;
ll min(ll X, ll Y){return X>Y?Y:X;}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N-1; i++) scanf("%lld", A+i);
	for(int i=0; i<N; i++) {
		ll x;
		scanf("%lld", &x);
		ans += (m = min(m, x)) * A[i];
	}
	printf("%lld", ans);
}
