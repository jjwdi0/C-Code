#include <stdio.h>

int N, M, A[8][8], B[8][8], row[8], col[8], r[8], c[8];
bool chk[8][8];

void fill(int x, int y) {
	for(int i=0; i<8; i++) B[i][y]++, B[x][i]++;
	B[x][y]--;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<64; i++) scanf("%d", &A[i/8][i%8]), row[i/8] += A[i/8][i%8], col[i%8] += A[i/8][i%8];
	for(int i=0; i<8; i++) for(int j=0; j<8; j++) {
		int s = row[i] + col[j] - A[i][j];
		if((N - s) & 1) chk[i][j] = 1;
	}
	for(int i=0; i<64; i++) if(chk[i/8][i%8]) fill(i/8, i%8);
	for(int i=0; i<64; i++) r[i/8] += B[i/8][i%8] + N, c[i%8] += B[i/8][i%8] + N;
	for(int i=0; i<8; puts(""), i++) for(int j=0; j<8; j++) {
		int s = r[i] + c[j] - B[i][j] - N;
		int t = row[i] + col[j] - A[i][j];
		if((s - t) % 4 && chk[i][j]) printf("- ");
		else if(chk[i][j]) printf("+ ");
		else printf(". ");
	}
}
