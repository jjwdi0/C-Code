#include <stdio.h>
#include <string.h>

char a[53], b[53];
int ans = 1e9, cnt;
int min(int X, int Y){ return X > Y ? Y : X; }

int main() {
	scanf("%s %s", a, b);
	for(int i=0; i<=strlen(b)-strlen(a); i++) {
		cnt = 0;
		for(int j=i; j<i+strlen(a); j++) cnt += (a[j-i] != b[j]);
		ans = min(cnt, ans);
	}
	printf("%d", ans);
}
