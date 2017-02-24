#include <stdio.h>
#include <algorithm>
using namespace std;

int a[4005], b[4005], c[4005], d[4005], sum1[4001*4001], sum2[4001*4001], n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d %d %d %d", a+i, b+i, c+i, d+i);
	for(int i = 0; i < n; i++) for(int j = 0 ; j < n ; j++) sum1[i * n + j] = a[i] + b[j], sum2[i * n + j] = c[i] + d[j];
	sort(sum1, sum1 + n * n);
	sort(sum2, sum2 + n * n);
	int ans = 0;
	for(int i = 0; i < n * n; i++) ans += upper_bound(sum2, sum2 + n * n, -sum1[i]) - lower_bound(sum2, sum2 + n * n, -sum1[i]);
	printf("%d", ans);
}
