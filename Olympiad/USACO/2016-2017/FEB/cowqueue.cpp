#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

int N, ans;
pr A[103];

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &A[i].first, &A[i].second);
    sort(A, A+N);
    for(int i=0; i<N; i++) {
        ans = max(ans, A[i].first);
        ans += A[i].second;
    }
    printf("%d\n", ans);
}
