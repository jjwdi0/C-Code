#include <stdio.h>
#include <algorithm>
using namespace std;

int a, b, c, d, e;

int main() {
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("%d", min(a * e, b + max(0, e - c) * d));
}
