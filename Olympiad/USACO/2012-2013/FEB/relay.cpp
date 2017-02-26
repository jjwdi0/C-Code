#include <stdio.h>

int n, chk[1002], a[1002], loop[1002], cnt, k;

void f(int x) {
    if(chk[x] == 2) { loop[k] = 1; return; }
    if(a[x]) { chk[x]++; f(a[x] - 1); }
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", a+i);
    for(int i=0; i<n; i++) {
    	f(i);
    	for(int j=0; j<n; j++) chk[j] = 0;
	}
    for(int i=0; i<n; i++) if(loop[i]) cnt++;
    printf("%d", n - cnt);
}
