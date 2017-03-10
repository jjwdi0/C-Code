#include <stdio.h>
#define MOD 10007

int N, A[1003], D[1003][8];
char c;

int main() {
	scanf("%d\n", &N);
	for(int i=0; i<N; i++) scanf("%c", &c), A[i] = (c == 'J' ? 0 : (c == 'O' ? 1 : 2));
	D[0][1] = 1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<8; j++) {
			if(D[i][j]) {
				D[i][j] %= MOD;
				for(int k=0; k<8; k++) if(((1 << A[i]) & k) && (k & j)) D[i+1][k] += D[i][j];
			}
		}
	}
	int ans = 0;
	for(int i=0; i<8; i++) ans += D[N][i];
	printf("%d", ans % MOD);
}
