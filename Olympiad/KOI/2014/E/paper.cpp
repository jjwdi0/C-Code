#include <stdio.h>

int B[1015][1015]={0};
int A[1000][5], N;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
		scanf("%d %d %d %d", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
    	for(int j=A[i][0]; j < A[i][0] + A[i][2]; j++) for(int k=A[i][1]; k < A[i][1] + A[i][3]; k++) B[j][k] = i + 1;
	}
    for(int i=0; i<1002; i++) for(int j=0; j<1002; j++) if(B[i][j]) A[B[i][j]-1][4]++;
    for(int i=0; i<N; i++) printf("%d\n", A[i][4]);
}
