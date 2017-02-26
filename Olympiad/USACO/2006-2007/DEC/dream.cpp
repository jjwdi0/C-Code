#include <stdio.h>

int a[10], s, e;

int main() {
	scanf("%d%d", &s, &e);
	for(int i=s; i<=e; i++) {
		int temp = i;
		while(temp) {
			a[temp % 10]++;
			temp /= 10;
		}
	}
	for(int i=0; i<10; i++) printf("%d ", a[i]);
}
