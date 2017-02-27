#include <stdio.h>
#include <algorithm>
using namespace std;

long long a[805], b[805], cnt;
int n;

int main() {
    scanf("%lld", &n);
    for(int i=0; i<n; i++) scanf("%lld", a+i);
    for(int i=0; i<n; i++) scanf("%lld", b+i);
    sort(a, a+n);
    sort(b, b+n);
    for(int i=0; i<n; i++) cnt += (long long)(a[i] * b[n-i-1]);
    printf("%lld", cnt);
}
