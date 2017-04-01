#include <bits/stdc++.h>
using namespace std;

int N, K, A[203], D[203][203];

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d", A+i);
    for(int i=1; i<=N; i++) for(int j=i; j; j--) {
        D[j][i] = 2e9;
        for(int k=j; k<i; k++) D[j][i] = min(D[j][i], D[j][k] + D[k+1][i] + (A[k+1] != A[j]));
        if(i == j) D[j][i] = 0;
    }
    printf("%d\n", D[1][N]);
}
