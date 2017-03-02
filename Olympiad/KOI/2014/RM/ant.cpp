#include <stdio.h>

int a, b, c, d, e;

int main() {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    c += e;
    d += e;
    c = c % (2 * a);
    d = d % (2 * b);
    if(c / a == 1) printf("%d ", 2 * a - c);
    else printf("%d ", c);
    if(d / b == 1) printf("%d", b - d + b);
    else printf("%d", d);
}
