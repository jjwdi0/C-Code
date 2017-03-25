#include <bits/stdc++.h>
using namespace std;

int N, K, A[100003], B[100003], cnt;

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0; i<K; i++) scanf("%d %d", A+i, B+i);
    sort(A, A+K);
    sort(B, B+K);
    for(int i=0; i<k; i++) cnt += abs(A[i] - A[K/2]) + abs(B[i] - B[K/2]);
    printf("%d\n", cnt);
}
