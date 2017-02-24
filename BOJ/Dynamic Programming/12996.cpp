#include <stdio.h>
#define MOD 1000000007

int N, A, B, C, D[53][53][53][53];

void ch(int &x, int y) {x = (x + y) % MOD;}
int kth(int x, int k) {return (x >> k) & 1;}

int main() {
	scanf("%d %d %d %d", &N, &A, &B, &C);
	D[0][0][0][0] = 1;
	for(int i=0; i<N; i++) for(int j=0; j<=A; j++) for(int k=0; k<=B; k++) for(int p=0; p<=C; p++) if(D[i][j][k][p]) {
		int u = D[i][j][k][p];
		for(int it=1; it<8; it++) ch(D[i+1][j+kth(it,2)][k+kth(it,1)][p+kth(it,0)], u);
	}
	printf("%d\n", D[N][A][B][C]);
}