#include <stdio.h>
#define INF 987654321

int N, A[20003][2]={1000,1000}, D1[2][2003], D2[2][2003];

int min(int X, int Y){return X>Y?Y:X;}
int abs(int x){return x>0?x:-x;}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d %d", &A[i][0], &A[i][1]);
        A[i][0] += 1000;
        A[i][1] += 1000;
    }
    for(int i=0; i<=2000; i++) for(int j=0; j<=1; j++) D1[j][i] = D2[j][i] = INF;
    D1[0][1000] = 0, D2[0][1000] = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=2000; j++) D1[(i+1)&1][j] = D2[(i+1)&1][j] = INF;
        for(int j=0; j<=2000; j++) {
            if(D1[i&1][j] < INF) {
                D1[(i+1)&1][j] = min(D1[(i+1)&1][j], D1[i&1][j] + abs(A[i][0] - A[i+1][0]));
                D2[(i+1)&1][A[i][0]] = min(D2[(i+1)&1][A[i][0]], D1[i&1][j] + abs(A[i+1][1] - j));
            }
            if(D2[i&1][j] < INF) {
                D2[(i+1)&1][j] = min(D2[(i+1)&1][j], D2[i&1][j] + abs(A[i][1] - A[i+1][1]));
                D1[(i+1)&1][A[i][1]] = min(D1[(i+1)&1][A[i][1]], D2[i&1][j] + abs(A[i+1][0] - j));
            }
        }
    }
    int ans = INF;
    for(int i=0; i<=2000; i++) ans = min(min(D2[N&1][i], ans), D1[N&1][i]);
    printf("%d\n", ans);
}
