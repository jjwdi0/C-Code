#include <stdio.h>
#define MAX 1<<23

long long tree[MAX], cnt;
int n, k, hash_array[1000005], pmt[500005];

void update(int x) {
    tree[x]++;
    if(x == 1) return;
    update(x / 2);
}

long long q(int x, int y) {
    long long m = 0;
    while(x < y) {
        if(x % 2 == 1) m += tree[x++];
        if(y % 2 == 0) m += tree[y--];
        x >>= 1, y >>= 1;
    }
    if(x == y) m += tree[x];
    return m;
}

int init() {
    int p = 1;
    while(p < n) p <<= 1;
    return p;
}

int main() {
    scanf("%lld", &n);
    for(int i=1, x; i<=n; i++) {
        scanf("%d", &x);
        hash_array[x]=i;
    }
    for(int i=0, x; i<n; i++) {
        scanf("%d", &x);
        pmt[i] = hash_array[x];
    }
    k = init();
    for(int i=0; i<n; i++) {
        update(k + pmt[i] - 1);
        cnt += q(k + pmt[i], 2 * k - 1);
    }
    printf("%lld", cnt);
}
