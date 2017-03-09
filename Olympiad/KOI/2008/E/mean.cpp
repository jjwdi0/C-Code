#include <stdio.h>
#include <algorithm>
using namespace std;

double a[100005], cnt1, cnt2;
int n, k;

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) scanf("%lf", &a[i]);
    sort(a, a+n);
    for(int i=0; i<n; i++) {
		if(i < k) cnt2 += a[k];
    	else if(i > n - k - 1) cnt2 += a[n-k-1];
    	else cnt1 += a[i], cnt2 += a[i];
	}
    printf("%.2f\n%.2f", cnt1 / (double)(n - 2 * k) + 1e-9, cnt2 / (double)n + 1e-9);
}
