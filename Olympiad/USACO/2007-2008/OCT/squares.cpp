#include <stdio.h>

int N, cnt;

int main() {
	scanf("%d", &N);
	for(int i=1; i<=500; i++) for(int j=i; j<=500; j++) if(j * j == i * i + N) cnt++;
	printf("%d", cnt);
}
