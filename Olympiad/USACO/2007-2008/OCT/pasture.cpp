#include <stdio.h>

int N, D[10003][5];

int main() {
	scanf("%d", &N);
	for(int i=0; i<=100; i++) D[i*i][1]=1;
	for(int i=0; i<=10000; i++) for(int j=1; j<4; j++) if(D[i][j]) for(int k=0; k<=100; k++) {
		if(i + k * k > 10000) break;
		D[i+k*k][j+1] += D[i][j];
	}
	printf("%d", D[N][4]);
}
