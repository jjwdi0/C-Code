#include <stdio.h>
#include <algorithm>
using namespace std;

int sum[10005], A[10005], N, K;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", A+i);
    sort(A, A+N);
    scanf("%d", &K);
    for(int i=1; i<=N; i++) sum[i] = A[i-1] + sum[i-1];
    for(int i=0; i<N; i++) if(A[i] > (K - sum[i]) / (N - i)) return printf("%d", (K - sum[i]) / (N - i)),0;
    printf("%d", A[N - 1]);
}
