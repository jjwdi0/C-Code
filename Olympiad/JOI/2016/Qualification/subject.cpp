#include <stdio.h>
#include <algorithm>
using namespace std;

int a[4], b, c;

int main() {
	for(int i=0; i<4; i++) scanf("%d", a+i);
	scanf("%d%d", &b, &c);
	sort(a, a+4);
	printf("%d", a[1] + a[2] + a[3] + max(b, c));
}
