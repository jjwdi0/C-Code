#include <bits/stdc++.h>
using namespace std;

int N, L, A[3005], B[3005], ans;

int main() {
    scanf("%d %d", &N, &L);
    for(int i=1; i<=N; i++) scanf("%d %d", A+i, B+i);
    for(int i=1; i<N; i++) if(B[i] != B[i+1]) ans = max(ans, L - A[i] - A[i+1] >> 1);
    printf("%d\n", ans);
}
