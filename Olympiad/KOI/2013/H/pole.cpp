#include <stdio.h>
#define MAX_N 100005
typedef long long ll;

ll A[MAX_N], l=1, r=1e9;
int N;

ll abs(ll x) { return x>0?x:-x; }

ll f(ll x) {
	ll res = 0;
	for(int k=0; k<N; k++) res += abs((ll)k * x - A[k]);
	return res;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lld", A+i);
	while(l + 2 < r) {
		ll u = (l * 2 + r)/3, v = (l + r * 2)/3;
		ll x = f(u), y = f(v);
		if(x > y) l = u;
		else r = v;
	}
	if(l + 2 == r) printf("%lld", f(l) < f(l + 1) ? f(l) : (f(l + 1) < f(r) ? f(l + 1) : f(r)));
	else if(l + 1 == r) printf("%lld", f(l) < f(r) ? f(l) : f(r));
	else printf("%lld", f(l));
}
