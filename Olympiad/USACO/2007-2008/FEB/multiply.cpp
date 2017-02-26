#include <stdio.h>
#include <string.h>

char a[10005], b[10005];
long long cnt1, cnt2;

int main() {
	scanf("%s %s", a, b);
	int len = strlen(a);
	for(int i=0; i<len; i++) cnt1 += (a[i] - '0');
	len = strlen(b);
	for(int i=0; i<len; i++) cnt2 += (b[i] - '0');
	printf("%lld", cnt1 * cnt2);
}
