#include <bits/stdc++.h>
using namespace std;

int N, M, g, i, cnt, j, det[2005][2005];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
    scanf("%d %d", &N, &M);
    for(i=N; i<=M; i++) for(j=1; j<=i; j++) g = gcd(j, i), det[j/g][i/g]++;
    for(i=0; i<=M; i++) for(j=0; j<=M; j++) if(det[i][j]) cnt++;
    printf("%d", cnt);
}
