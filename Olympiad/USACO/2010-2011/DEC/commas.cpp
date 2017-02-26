#include <stdio.h>
#include <string.h>

int n, r;
char a[201];

int main() {
    scanf("%s", a);
	n = strlen(a);
    r = n % 3;
    for(int i = 0; i < n; i++) {
        if(i > 0 && i % 3 == r) printf(",");
        printf("%c", a[i]);
    }
}
