#include <stdio.h>

int N, K, A[100000], B = -1000000, c;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<K; i++) c += A[i];
	if(c > B) B = c;
	for(int i=1; i<N-K+1; i++) {
		c = c - A[i-1] + A[i+K-1];
		if(c > B) B = c;
	}
	printf("%d\n", B);
}
