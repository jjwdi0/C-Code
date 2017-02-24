#include <stdio.h>

int a;

int main() {
	scanf("%d", &a);
	if(a % 10) printf("-1");
	else printf("%d %d %d", a / 300, (a % 300) / 60, (a % 60) / 10);
}
