#include <stdio.h>

int N;
int f(int x) { return x == 1 ? 0 : (x % 2 ? f(x * 3 + 1) : f (x / 2)) + 1; }

int main() {
	scanf("%d", &N);
	printf("%d", f(N));
}
