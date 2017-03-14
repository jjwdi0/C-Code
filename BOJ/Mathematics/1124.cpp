#include <stdio.h>

int A, B, ans;
bool isprime[100005];

bool is_under_prime(int x) {
	int cnt = 0;
	for(int i=2; i*i<=x; i++) while(x % i == 0) cnt++, x /= i;
	cnt += (x > 1); 
	return !isprime[cnt];
}

int main() {
	scanf("%d %d", &A, &B);
	for(int i=2; i*i<=100000; i++) for(int j=i*i; j<=100000; j+=i) isprime[j] = 1; isprime[1] = true;
	for(int i=A; i<=B; i++) ans += is_under_prime(i);
	printf("%d", ans);
}
