#include <stdio.h>

int A[8];

int main() {
	for(int i=0; i<8; i++) scanf("%d", A+i);
	int x, y, z;
	x = A[7] - A[6];
	y = A[5] - A[4] + x;
	z = A[3] - A[2] + y;
	printf("%d\n%d\n%d", z, y, x);
}
