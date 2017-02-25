#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

int N, M, K, ans = 1e9;
int A[100005];

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0, x; i<K; ++i) scanf("%d", &x), A[x] = 1;
    for(int i=1; i<=N; i++) A[i] += A[i-1];
    for(int i=M; i<=N; i++) {
        ans = min(ans, A[i] - A[i-M]);
    }
    printf("%d\n", ans);
}

