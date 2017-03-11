#include <stdio.h>

int A, N = 4, cnt;

int main() {
	while(N--) {
		scanf("%d", &A);
		cnt += A;
	}
	printf("%d\n%d", cnt / 60, cnt % 60);
}
