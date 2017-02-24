#include <stdio.h>
 
int A[1007][4];
int N, K;
int rank = 1;
 
int main() {
    scanf("%d %d", &N, &K);
    for(int i=0, x; i<N; i++) {
        scanf("%d", &x);
        scanf("%d %d %d", &A[x][1], &A[x][2], &A[x][3]);
    }
    for(int i=1; i<=N; i++) {
        if(A[i][1] > A[K][1] 
        || A[i][1] == A[K][1] && A[i][2] > A[K][2]
        || A[i][1] == A[K][1] && A[i][2] == A[K][2] && A[i][3] > A[K][3]) rank++;
    }
    printf("%d\n", rank);
}
