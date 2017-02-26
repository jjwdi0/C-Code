#include <stdio.h>
#define max(x,y) (x)>(y)?(x):(y)

int n, a[1003], ans;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", a+i);
	for(int i=0; i<n; i++) {
		int prev = -1, cnt = 1;
		for(int j=0; j<=n; j++) {
			if(a[j] == a[i]) continue;
			if(a[j] == prev) cnt++;
			else ans = max(ans, cnt), cnt = 1, prev = a[j];
		}
	}
	printf("%d\n", ans);
}
