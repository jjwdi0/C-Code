#include <stdio.h>

int t, D[35][35];

int combination(int n, int r) {
	if(D[n][r]) return D[n][r];
    if(r == 0 || n == r) return D[n][r] = 1;
    return D[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
    int n, r;
    scanf("%d", &t);
    while(t--) {
    	scanf("%d %d", &n, &r);
        printf("%d\n", combination(r, n));
	}
}
