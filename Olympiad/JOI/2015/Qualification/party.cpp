#include <stdio.h>

int N, M, A[103], B[103], score[103];

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) scanf("%d", A+i);
	for(int i=0; i<M; i++) {
		int cnt = 0;
		for(int j=1; j<=N; j++) {
			scanf("%d", B+j);
			if(B[j] == A[i]) cnt++, score[j]++;
		}
		score[A[i]] += N - cnt;
	}
	for(int i=1; i<=N; i++) printf("%d\n", score[i]);
}
