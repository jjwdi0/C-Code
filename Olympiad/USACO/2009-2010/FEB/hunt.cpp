#include <stdio.h>

int N, M;

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) if(N % i == 0) for(int j=1; j<=M; j++) if(M % j == 0) printf("%d %d\n", i, j);
}
