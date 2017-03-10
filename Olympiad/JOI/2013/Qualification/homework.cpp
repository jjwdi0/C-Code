#include <stdio.h>
#include <algorithm>
using namespace std;

int a, b, c, d, e;

int main() {
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d", max(0, a - max((b - 1) / d + 1, (c - 1) / e + 1)));
}
