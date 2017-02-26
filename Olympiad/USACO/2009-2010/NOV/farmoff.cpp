#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

struct data{
	ll util, wei;
}cow[1500005];

int n, m;
ll pow5d[1500005], pow5h[1500005], pow3[1500005], pow2[1500005];
int a, b, c, d, e, f, g, h;

bool cmp(const data &x, const data &y) {
	if(x.util == y.util)return x.wei < y.wei;
	return x.util > y.util;
}

int main() {
	scanf("%d %d %d %d %d %d %d %d %d %d", &n, &a, &b, &c, &d, &e, &f, &g, &h, &m);
	for(int i=0; i<n*3; i++) {
		ll temp = 1LL;
		for(int j=0; j<5; j++) {
			temp *= (ll)i;
			if(temp > d) temp %= (ll)d;
		}
		pow5d[i] = temp;
		temp = 1LL;
		for(int j=0; j<5; j++) {
			temp *= (ll)i;
			if(temp > h) temp %= (ll)h;
		}
		pow5h[i] = temp;
		temp = 1LL;
		for(int j=0; j<3; j++) {
			temp *= (ll)i;
			if(temp > h) temp %= (ll)h;
		}
		pow3[i] = temp;
		temp = 1LL;
		for(int j=0; j<2; j++) {
			temp *= (ll)i;
			if(temp > d) temp %= (ll)d;
		}
		pow2[i] = temp;
	}
	for(int i=0; i<n*3; i++) {
		cow[i].wei = a * pow5d[i] + b * pow2[i] + c;
		cow[i].wei %= d;
		cow[i].util = e * pow5h[i] + f * pow3[i] + g;
		cow[i].util %= h;
	}
	sort(cow, cow + 3 * n, cmp);
	ll cnt = 0;
	for(int i=0; i<n; i++) {
		cnt += cow[i].wei;
		cnt %= (ll)m;
	}
	printf("%lld\n", cnt);
}
