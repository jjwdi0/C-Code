#include <stdio.h>

int N, T;

int main() {
	scanf("%d", &N);
	for(int i=0; i<9; N -= T,i++) scanf("%d", &T);
	printf("%d", N);
}
