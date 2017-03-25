#include <stdio.h>

int k;

int main() {
	char a[50];
	gets(a);
	for(int i=1; i<strlen(a); i++) k += a[i] == a[i-1] ? 5 : 10; 
	printf("%d", k + 10);
}
