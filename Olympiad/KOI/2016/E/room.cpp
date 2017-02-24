#include <stdio.h>

int A[6][2], N, K, cnt;

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0, x, y; i<N; i++) {
        scanf("%d %d", &x, &y);
        A[y-1][x]++;
    }
    for(int i=0; i<6; i++) for(int j=0; j<2; j++) if(A[i][j]) cnt += (A[i][j] - 1) / K + 1;
    printf("%d", cnt);
}
