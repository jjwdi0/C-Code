#include <stdio.h>

int N, M, A[1003], B[1003], loc = 1, cnt;

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", A+i);
	for(int i=0; i<M; i++)scanf("%d", B+i);
	while(loc < N) {
		loc += B[cnt++];
		loc += A[loc];
	}
	printf("%d", cnt);
}
