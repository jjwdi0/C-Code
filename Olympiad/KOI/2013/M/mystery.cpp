#include <stdio.h>

int N, A[32], B[32], k, val;

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", B+i);
	for(int i=0; i<N; i++) {
		k = (k + val) % N;
		while(A[k]) k = (k + 1) % n;
		A[k] = B[i];
		val = A[k];
	}
	printf("%d\n", N);
	for(int i=0; i<N; i++) printf("%d ", A[i]);
}
