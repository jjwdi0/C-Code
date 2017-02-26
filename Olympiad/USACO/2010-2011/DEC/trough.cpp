#include <stdio.h>

int n, m, a[103][2], ans = -1;
char ch[23];

bool chk(int x) {
	for(int i=0; i<m; i++) if(__builtin_popcount(a[i][0] & x) != a[i][1]) return false;
	return true;
}

void print_ans(int x) {
	for(int i=n-1; i>=0; i--) printf("%d", !!(x & (1 << i)));
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%s %d", ch, &a[i][1]);
		for(int j=0; j<n; j++) a[i][0] |= ((ch[j] - '0') << (n - j - 1));
	}
	for(int i=0; i<1<<n; i++) {
		if(chk(i)) {
			if(~ans) return puts("NOT UNIQUE"),0;
			ans = i;
		}
	}
	if(~ans) print_ans(ans);
	else puts("IMPOSSIBLE");
}
