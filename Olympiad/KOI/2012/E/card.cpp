#include <stdio.h>

int A[2][10], M, N, k;

int main() {
    for(int i=0; i<2; i++) for(int j=0; j<10; j++) scanf("%d", &A[i][j]);
    for(int i=0; i<10; i++) {
	    if(A[0][i] > A[1][i]) M += 3, k = 1;
	    else if(A[0][i] < A[1][i]) N += 3, k = 2;
	    else M++, N++;
    }
    printf("%d %d\n", M, N);
    if(M > N) printf("A");
    else if(M < N) printf("B");
    else if(k == 1) printf("A");
    else if(k == 2) printf("B");
    else printf("D");
}
