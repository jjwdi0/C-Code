#include <stdio.h>

int a[103][103], n, m, chk[103][103], cnt, mi;

int max(int x, int y) { return x > y ? x : y; }
int get(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= n) return -1;
	if(chk[x][y] == 1) return -1;
	return a[x][y];
}

void f(int x, int y) {
	chk[x][y] = 1;
	if(get(x + 1, y) > 0) f(x + 1, y);
	if(get(x, y - 1) > 0) f(x, y - 1);
	if(get(x, y + 1) > 0) f(x, y + 1);
	if(get(x - 1, y) > 0) f(x - 1, y);
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n*n; m = max(a[i/n][i%n], m),i++)
	scanf("%d", &a[i/n][i%n]);
	m--;
	while(m--) {
		for(int i=0; i<n*n; i++) { a[i/n][i%n]--; chk[i/n][i%n] = 0; }
		for(int i=0; i<n*n; i++) {
			if(chk[i/n][i%n] == 0 && a[i/n][i%n] > 0) f(i / n, i % n), cnt++;
		}
		mi = max(cnt, mi);
		cnt = 0;
	}
	if(mi == 0) mi++;
	printf("%d", mi);
}
