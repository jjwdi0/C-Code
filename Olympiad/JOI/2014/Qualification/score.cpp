#include <stdio.h>

int a[5], cnt;

int main() {
	for(int i=0; i<5; i++) {
		scanf("%d", a + i);
		if(a[i] < 40) cnt += 8;
		else cnt += a[i] / 5;
	}
	printf("%d", cnt);
}
