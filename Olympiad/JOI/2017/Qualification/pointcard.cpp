#include <bits/stdc++.h>
using namespace std;

int N, M, ans, mn = 1e9;

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0, x, y; i<M; i++) {
        scanf("%d %d", &x, &y);
        mn = min(mn, x);
        ans += max(0, N - x);
    }
    printf("%d\n", ans - N + mn);
}

