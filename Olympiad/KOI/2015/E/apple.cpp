#include <stdio.h>

int A[1000][2], N, c;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]), c += A[i][1] % A[i][0];
    printf("%d", c);
}
