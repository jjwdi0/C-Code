#include <stdio.h>
#define MOD 1000000009

long long D[1000005];
int N, K;

int main() {
	scanf("%d %d", &N, &K);
	D[0] = 1;
	D[1] = K;
	D[2] = K * K % MOD;
	D[3] = D[2] * K % MOD;
	D[4] = D[3] * K % MOD;
	D[5] = (D[4] * K - D[0] * 2) % MOD;
	D[6] = (D[5] * K - D[1] * 2) % MOD;
	for(int i=7; i<=N; i++) D[i] = (D[i-1] * K - D[i-5] * 2 + D[i-7]) % MOD;
	printf("%d", D[N] < 0 ? D[N] + MOD : D[N]);
}
