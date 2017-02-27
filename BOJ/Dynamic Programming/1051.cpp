#include <stdio.h>
int a[53][53], DT[53][53], n, m, i, j;
int min(int x, int y) { return x > y ? y : x; }
int max(int x, int y) { return x > y ? x : y; }
int f(int x, int y) {
	int q = min(x, y);
    if(D[x][y]) return D[x][y];
    if(x * y == 0) return D[x][y] = 1;
    D[x][y] = max(f(x - 1, y), f(x, y - 1));
    for(int p=0; p<q; p++) {
        if(a[x - q + p][y] == a[x - q + p][y - q + p] 
		&& a[x - q + p][y - q + p] == a[x][y] 
		&& a[x][y - q + p] == a[x][y] 
		&& (q - p + 1) * (q - p + 1) > D[x][y]) {
            D[x][y] = (q - p + 1) * (q - p + 1);
            break;
        }
    }
    return D[x][y];
}

int main() {
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%1d", &a[i][j]);
    printf("%d", f(n-1, m-1));
}
