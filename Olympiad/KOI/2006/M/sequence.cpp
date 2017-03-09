#include <stdio.h>

int n, a, b;

int f(int x) {
    if(x == 1) return 0;
    if(x % 4 == 0) return f(x / 4) + 1;
    for(int i=2; i<=x; i++) if(x % i == 0) break;
    return f(x / i) + 1;
}

int main() {
    scanf("%d", &n);
    a = (n + 2) / 3;
    b = f(n);
    printf("%d %d", a, b);
}
