#include <bits/stdc++.h>
using namespace std;

int N, pre[13]={2,2,2,2,2,2,2,2,2,2,2,2}, ans;

int main() {
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);
    scanf("%d", &N);
    for(int i=0, x, y; i<N; i++) {
        scanf("%d %d", &x, &y);
        if(pre[x] == 2) pre[x] = y;
        else if(pre[x] != y) ans++;
        pre[x] = y;
    }
    printf("%d\n", ans);
}
