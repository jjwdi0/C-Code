#include <bits/stdc++.h>
using namespace std;

int R, C, N;
int X1[5003], X2[5003], Y1[5003], Y2[5003];
queue<int> pq;
int dist[5003];

bool f(int x, int y, int z) { return x <= y && y <= z; }

int main() {
    scanf("%d %d %d", &R, &C, &N);
    for(int i=1, x; i<=N; i++) {
        scanf("%d %d %d %d %d", &x, X1 + i, Y1 + i, X2 + i, Y2 + i);
        if(X1[i] > X2[i]) swap(X1[i], X2[i]);
        if(Y1[i] > Y2[i]) swap(Y1[i], Y2[i]);
    }
    int sx, sy, fx, fy;
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
    for(int i=1; i<=N; i++) dist[i] = 1e9;
    for(int i=1; i<=N; i++) if(f(X1[i], sx, X2[i]) && f(Y1[i], sy, Y2[i])) dist[i] = 1, pq.push(i);
    while(!pq.empty()) {
        int u = pq.front(); pq.pop();
        int cost = dist[u];
        if(f(X1[u], fx, X2[u]) && f(Y1[u], fy, Y2[u])) return !printf("%d\n", cost);
        for(int i=1; i<=N; i++) {
            if(X1[u] == X2[u]) {
                if(X1[i] == X2[i]) {
                    if(X1[i] != X1[u] || Y2[i] < Y1[u] || Y2[u] < Y1[i]) continue;
                    if(dist[i] > cost + 1) dist[i] = cost + 1, pq.push(i);
                }
                else {
                    if(f(Y1[u], Y1[i], Y2[u]) && f(X1[i], X1[u], X2[i]) && dist[i] > cost + 1) dist[i] = cost + 1, pq.push(i);
                }
            }
            else {
                if(Y1[i] == Y2[i]) {
                    if(Y1[i] != Y1[u] || X2[i] < X1[u] || X2[u] < X1[i]) continue;
                    if(dist[i] > cost + 1) dist[i] = cost + 1, pq.push(i);
                }
                else {
                    if(f(X1[u], X1[i], X2[u]) && f(Y1[i], Y1[u], Y2[i]) && dist[i] > cost + 1) dist[i] = cost + 1, pq.push(i);
                }
            }
        }
    }
}

