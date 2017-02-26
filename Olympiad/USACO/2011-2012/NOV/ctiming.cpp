#include <stdio.h>

int a, b, c;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	int t = (a - 11) * 1440 + (b - 11) * 60 + (c - 11);
	printf("%d", t >= 0 ? t : -1);
}
