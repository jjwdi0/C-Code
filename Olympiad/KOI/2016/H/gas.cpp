#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define INF (1LL)<<58
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int>> tr;

int N, M, A[2505];
ll D[2505][2505];
vector<pair<int, int>> v[2505];
priority_queue<tr, vector<tr>, greater<tr>> q;

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) scanf("%d", A+i);
    for(int i=0, x, y, z; i<m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        v[x].push_back({y, z}); v[y].push_back({x, z});
    }
    for(int i=0; i<=2500; i++) for(int j=0; j<=2500; j++) D[i][j] = INF;
    q.push( { 0LL, { A[1], 1 } } );
    while(!q.empty()) {
        tr T = q.top(); q.pop();
        ll c = T.first;
        int x = T.second.first, y = T.second.second;
        if(dp[y][x] <= c)continue;
        dp[y][x] = c;
        if(y == N) return printf("%lld", c), 0;  
        for(int i=0; i<v[y].size(); i++) {
            if(dp[v[y][i].first][min(x, a[v[y][i].first])] <= c + (ll)x * (ll)v[y][i].second)continue;
            q.push({c + (ll)x * (ll)v[y][i].second, {min(x, a[v[y][i].first]), v[y][i].first}});
        }
    }
}
