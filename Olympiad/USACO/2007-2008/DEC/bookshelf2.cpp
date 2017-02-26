#include <stdio.h>

int n, m, a[23], ans = 1e9;
int min(int X, int Y){ return X > Y ? Y : X; }

void f(int x, int cnt) {
	if(x == n || cnt >= m) {
		if(cnt >= m) ans = min(ans, cnt - m);
		return;
	}
	f(x + 1, cnt);
	f(x + 1, cnt + a[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", a+i);
	f(0, 0);
	printf("%d", ans);
}
