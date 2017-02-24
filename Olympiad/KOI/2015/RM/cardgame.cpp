#include <stdio.h>

int A[2][10], N, M, K;

int main() {
    for(int i=0; i<2; i++) for(int j=0; j<10; j++) scanf("%d", &A[i][j]);
    for(int i=0; i<10; i++) {
    	if(A[0][i] > A[1][i]) M++;
  		else if(A[0][i] < A[1][i]) N++;
    }
    if(N < M) printf("A");
    else if(N > M) printf("B");
    else printf("D");
}
