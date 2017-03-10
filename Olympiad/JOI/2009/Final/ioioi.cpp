#include <stdio.h>

char a[1000005];
int n, m, cur, ans;

int f(int x) {
	if(x >= n) return x - n + 1;
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", a);
	for(int i=0; i<=m; i++) {
		if(a[i] == 'I') {
			if(i >= 2 && a[i-2] == 'I' && a[i-1] == 'O') cur++, i++;
			else ans += f(cur), cur = 0;
		}
		else {
			if(cur > 0) ans += f(cur), cur = 0;
		}
	}
	ans += f(cur);
	printf("%d", ans);
}
