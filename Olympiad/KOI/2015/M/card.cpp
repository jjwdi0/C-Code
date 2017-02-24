#include <bits/stdc++.h>
using namespace std;

int D[2005][2005], N, A[2005], B[2005];

int f(int x, int y) {
	if(x > N || y > N) return D[x][y] = 0;
	if(~D[x][y]) return D[x][y];
	D[x][y] = max(f(x + 1, y), f(x + 1, y + 1));
	if(a[x] > b[y]) D[x][y] = max(D[x][y], f(x, y + 1) + b[y]);
	return D[x][y];
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<n; i++) scanf("%d", A+i);
	for(int i=0; i<n; i++) scanf("%d", B+i);
	for(int i=0; i<=n+2; i++) for(int j=0; j<=n+2; j++) D[i][j] = -1;
	printf("%d", f(0, 0));
}
