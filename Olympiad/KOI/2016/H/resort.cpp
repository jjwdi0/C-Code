#include <stdio.h>
#include <algorithm>
#define INF 1987654321
using namespace std;

int N, M, A[105], D[105][45];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0, t; i<M; i++) scanf("%d", &t), A[t] = 1;
    for(int i=0; i<=N; i++) for(int j=0; j<45; j++) D[i][j] = INF;
    D[0][0] = 0;
    for(int i=0; i<N; i++) {
        if(A[i + 1]) {
            for(int j=0; j<45; j++) if(D[i][j] != INF) D[i+1][j] = min(D[i+1][j], D[i][j]);
        }
        else {
            for(int j=0; j<45; j++) if(D[i][j] != INF) {
                D[i+1][j] = min(D[i+1][j], D[i][j] + 10000);
                D[i+3][j+1] = min(D[i+3][j+1], D[i][j] + 25000);
                D[i+5][j+2] = min(D[i+5][j+2], D[i][j] + 37000);
                if(j >= 3) D[i+1][j-3] = min(D[i+1][j-3], D[i][j]);
            }
        }
    }
    int ans = INF;
    for(int i=0; i<45; i++) ans = min(ans, D[N][i]);
    printf("%d\n", ans);
}
