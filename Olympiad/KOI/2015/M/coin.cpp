#include <stdio.h>

int k, a, b, p;

int main() {
    scanf("%d %d", &p, &k);
    for(int i=0; i<k; i++) {
        int n = p;
        scanf("%d %d", &a, &b);
        if(a >= b){
            a -= b, n -= b, b = 0;
            puts(a <= n / 2 + 1 ? "1" : "0");
        }
        else{
            b -= a, n -= a, a = 0;
            puts(b <= (n + 1) / 2 ? "1" : "0");
        }
    }
}
