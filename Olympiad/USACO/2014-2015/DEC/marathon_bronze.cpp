#include <stdio.h>
#define INF 1LL<<50
typedef long long ll;

ll ans = INF, dist;
int n, a[100005][2];
int abs(int X){return X > 0 ? X : -X;}
ll min(ll X, ll Y){return X > Y ? Y : X;}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
	for(int i=1; i<n; i++) dist += abs(a[i][0] - a[i-1][0]) + abs(a[i][1] - a[i-1][1]);
	for(int i=1; i<n-1; i++) ans = min(ans, dist - abs(a[i][0] - a[i-1][0]) - abs(a[i][1] - a[i-1][1]) - abs(a[i+1][0] - a[i][0]) - abs(a[i+1][1] - a[i][1]) + abs(a[i+1][0] - a[i-1][0]) + abs(a[i+1][1] - a[i-1][1]));
	printf("%lld", ans);
}
