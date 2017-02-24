#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T, N, A[22][2];
ll ans;

ll sz(int x, int y) {return 1LL * x * x + 1LL * y * y;}

int main() {
    scanf("%d", &T);
    while(T--) {
        ans = 1e18;
        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]);
        for(int i=0; i<1<<N; i++) if(__builtin_popcount(i) == N / 2) {
            int x = 0, y = 0;
            for(int j=0; j<N; j++) {
                if((1 << j) & i) x += A[j][0], y += A[j][1];
                else x -= A[j][0], y -= A[j][1];
            }
            ans = min(ans, sz(x, y));
        }
        printf("%.6f\n", sqrt(ans));
    }
}

