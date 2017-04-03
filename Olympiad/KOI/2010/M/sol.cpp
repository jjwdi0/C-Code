#include <stdio.h>
#include <algorithm>
using namespace std;
int n, a[100005], b[100005], c = 2147483640;
pair<int, int> ans;
bool cmp(int x, int y) { return x > y; }

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", a+i);
		b[i] = a[i];
	}
	sort(a, a+n);
	for(int i=0; i<n; i++) {
		int ind = lower_bound(a, a+n, -a[i]) - a;
		if(ind == n) ind--;
		bool update = false;
		if(a[i] == a[ind]) {
			ind++;
			update = true;
		}
		if(ind != n && a[i] != a[ind]) {
			if(c > abs(a[i] + a[ind])) {
				c = abs(a[i] + a[ind]);
				ans.first = a[i];
				ans.second = a[ind];
			}
		}
		if(update) ind--;
		ind--;
		if(ind < 0) continue;
		if(a[i] == a[ind]) ind--;
		if(ind < 0) continue;
		if(a[i] != a[ind]) {
			if(c > abs(a[i] + a[ind])) {
				c = abs(a[i] + a[ind]);
				ans.first = a[i];
				ans.second = a[ind];
			}
		}
	}
	printf("%d %d", ans.first, ans.second);
}
