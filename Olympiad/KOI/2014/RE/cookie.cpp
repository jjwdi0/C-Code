#include <stdio.h>

int a, b, c;

int main() {
	scanf("%d %d %d", &a, &b, &c);
	if(a * b < c) printf("0");
	else printf("%d", a * b - c);
}
