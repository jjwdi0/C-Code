#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int N, K;
string t[16];
int inf[16][2], digit_mod[801] = {1};
ll fact[17] = {1LL}, D[1<<16][103];
ll gcd(ll x, ll y){ return y ? gcd(y, x % y) : x; }

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) cin >> t[i];
	scanf("%d", &K);
	for(int i=0; i<N; i++) {
		int r = 0;
		for(auto j : t[i]) {
			r = r * 10 + (j - '0');
			if(r >= K) r %= K;
		}
		inf[i][0] = t[i].length(), inf[i][1] = r;
	}
	int temp = 1;
	for(int i=1; i<=800; i++) {
		temp *= 10;
		if(temp >= K) temp %= K;
		digit_mod[i] = temp;
	}
	for(int i=1; i<=15; i++) fact[i] = fact[i-1] * (ll)i;
	for(int i=0; i<N; i++) D[1 << i][ inf[i][1] ] = 1LL;
	for(int i=1; i<1<<N; i++) {
		for(int j=0; j<K; j++) {
			if(D[i][j]) {
				for(int it=0; it<N; it++) {
					if(i & (1 << it)) continue;
					D[i | (1 << it)][(j * digit_mod[inf[it][0]] + inf[it][1]) % K] += D[i][j];
				}
			}
		}
	}
	ll ans = D[(1 << N) - 1][0];
	ll g = gcd(ans, fact[N]);
	printf("%lld/%lld", ans / g, fact[N] / g);
}
