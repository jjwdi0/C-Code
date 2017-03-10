#include <stdio.h>

int a, b, c, d, e;
int min(int x, int y) { return x > y ? y : x; }

int main() {
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d", min(min(a, b), c) + min(d, e) - 50);
}
