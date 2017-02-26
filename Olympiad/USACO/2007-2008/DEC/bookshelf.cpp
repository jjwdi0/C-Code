#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[20005];
long long sum, m;

int main() {
	scanf("%d %lld", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", a+i);
	sort(a, a+n);
	for(int i=n-1; i>=0; i--) {
		sum += (long long)a[i];
		if(sum >= m) return !printf("%d", n - i);
	}
}
