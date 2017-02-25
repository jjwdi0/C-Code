#include <stdio.h>

int a, b, c, d;
int max(int x, int y) { return x > y ? x : y; }

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(a > d) printf("%d", b - a + d -c);
	else if(c > b) printf("%d", b - a + d - c);
	else if(a > c && b < d) printf("%d", d - c);
	else if(a < c && b > d) printf("%d", b - a);
	else printf("%d", max(d - a, b - c));
}
