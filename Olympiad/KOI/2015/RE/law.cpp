#include <stdio.h>

int n, a, c;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 5; i++) {
        scanf("%d", &a);
        if(a == n) c++;
    }
    printf("%d", c);
}
