#include <stdio.h>

int A[1000][3], N;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(A[i][0] < A[j][0] && A[i][1] < A[j][1]) A[i][2]++;
    for(int i=0; i<N; i++) printf("%d ", A[i][2] + 1);
}
