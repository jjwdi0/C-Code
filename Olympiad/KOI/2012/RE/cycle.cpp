#include <stdio.h>

int a[1000000];

int main() {
	int n, k, b, u;
	scanf("%d %d", &k, &b);
	a[k] = 1;
	u = k;
	for(int i=2; i<1234567; i++) {
		u = k % b * u % b % b;
		if(a[u]) return !printf("%d", i-a[u]);
		else a[u] = i;
	}
}
