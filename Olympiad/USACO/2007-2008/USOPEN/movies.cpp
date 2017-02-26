#include <stdio.h>

int N, C, A[20], ans;
int max(int X, int Y){ return X > Y ? X : Y; }

int main() {
	scanf("%d %d", &C, &N);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<1<<N; i++) {
		int cnt = 0;
		for(int j=0; j<N; j++) if(i & (1 << j)) cnt += A[j];
		ans = max(ans, cnt > C ? 0 : cnt);
	}
	printf("%d", ans);
}
