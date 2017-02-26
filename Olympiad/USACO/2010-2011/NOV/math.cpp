#include <stdio.h>
typedef long long ll;

int A, B;
int first_digit(ll x) { while(x / 10) x /= 10; return (int)x; }

int log_n(ll x) {
	ll k = 1LL;
	int cnt = 0;
	while(k != x) cnt++, k <<= 1;
	return cnt;
}

int main() {
	scanf("%d %d", &A, &B); 
	for(ll i = (1LL << (A + 1)); i < (1LL << 62); i <<= 1) if(first_digit(i) == B)return printf("%d\n", log_n(i)), 0;
	puts("0");
}
