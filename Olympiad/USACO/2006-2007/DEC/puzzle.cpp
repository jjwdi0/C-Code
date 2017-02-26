#include <stdio.h>

int cnt, max, n, k, a[25];

void f(int x) {
    if(cnt > n) return;
    if(x == k + 1) {
		if(cnt > max) max = cnt;
    	return;
	} 
    f(x + 1), cnt += a[x-1];
    f(x + 1), cnt -= a[x-1];
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++) scanf("%d", a+i);
    f(1);
    printf("%d", max);
}
