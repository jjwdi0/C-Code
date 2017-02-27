#include <stdio.h>

bool sieve[1000005];
long long min, max;

int main() {
	scanf("%lld %lld", &min, &max);
	for(long long i=2; i*i<=max; i++) {
		for(long long j=min/(i*i)*(i*i); j<=max; j+=i*i) {
			if(j < min) continue;
			sieve[j-min+1] = 1;
		}
	}
	int ans = 0;
	for(int i=1; i<=max-min+1; i++) if(!sieve[i]) ans++;
	printf("%d", ans);
}
