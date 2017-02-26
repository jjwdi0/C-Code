#include <stdio.h>
 
int coin[105], ca[10005], re[10005], n, k;

int main() {
    scanf("%d %d", &n, &k);
    n ^= k ^= n ^= k;
    for(int i=0; i<n; i++) scanf("%d", &coin[i]);
    re[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(j < coin[i]) re[j] = ca[j];
            else re[j] = ca[j] + re[j-coin[i]];
        }
        for(int j=1; j<=k; j++) ca[j] = re[j];
    }
    printf("%d", re[k]);
}
