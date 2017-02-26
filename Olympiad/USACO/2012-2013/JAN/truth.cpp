#include <stdio.h>
 
int N, M, par[2005];
 
int find(int x) { return par[x] = (x == par[x] ? x : find(par[x])); }
 
int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N*2; i++) par[i] = i;
    for(int i=0, x, y; i<M; i++) {
        char q;
        scanf("%d %d %c", &x, &y, &q);
        if(q == 'L') {
            int u = find(x);
            int v = find(y + N);
            if(find(x) == find(y)) return !printf("%d\n", i);
            par[u] = v;
            par[find(x + N)] = find(y);
        }
        else {
            int u = find(x), v = find(y);
            if(find(x) == find(y + N)) return !printf("%d\n", i);
            par[u] = v;
            par[find(x + N)] = find(y + N);
        }
    }
    printf("%d\n", M);
}
