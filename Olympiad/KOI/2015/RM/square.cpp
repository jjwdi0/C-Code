#include <bits/stdc++.h>
using namespace std;

int N, M, D[10003][103];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
        if(i == j) D[i][j] = 1;
        else if(j * j - 3 * i <= 0) D[i][j] = D[i-j][j] + 1; // 이유 모름
        else {
            D[i][j] = 1e9;
            for(int k=1; k<j; k++) D[i][j] = min(D[i][j], D[i][k] + D[i][j-k]);
            for(int k=1; k<i; k++) D[i][j] = min(D[i][j], D[k][j] + D[i-k][j]);
        }
    }
    printf("%d\n", D[N][M]);
}

