#include <stdio.h>

int a, b, c, x, y, z;

int main() {
	for(int i=0; i<3; i++) {
		scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);
		c = a * 3600 + b * 60 + c;
		z = 3600 * x + 60 * y + z;
		z -= c;
		printf("%d %d %d\n", z / 3600, (z % 3600) / 60, z % 60);
	}
}
