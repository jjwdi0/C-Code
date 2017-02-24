#include <stdio.h>
#include <math.h>

int a, b, k;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
	scanf("%d %d", &a, &b);
	if(b == 0) return !printf("0 %d", a);
	k = (int)(sqrt(a) * sqrt(b));
	for(int i=k; i>0; i--) if(b % i == 0) if(gcd(i, b / i * a) == a) return !printf("%d %d", i, b/i*a);
}
