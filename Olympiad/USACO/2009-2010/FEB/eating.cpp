#include <stdio.h>
typedef long long ll;

int N, D, ans[55555];
ll A[55555];

bool chk(ll x) {
	ll res = 0;
	int j = 0;
	for(int i=0; i<D; i++) {
		res /= 2LL;
		while(res < x && j < N) res += A[j++];
		if(res < x) return false;
	}
	return true;
}

int main() {
    ll lo = 0LL, hi;
	scanf("%d %d", &N, &D);
	for(int i=0; i<N; i++) scanf("%lld", A+i), hi += A[i];
	while(lo <= hi) {
		ll mid = lo + hi >> 1;
		if(chk(mid)) lo = mid + 1;
		else hi = mid - 1;
	}
	printf("%lld\n", lo - 1);
	ll res = 0;
	int j = 0;
	for(int i=1; i<=D; i++) {
		res /= 2LL;
		while(res < lo - 1 && j < N) res += A[j], ans[j++] = i;
	}
	for(; j<N; j++) ans[j] = D;
	for(int i=0; i<N; i++) printf("%d\n", ans[i]);
}
