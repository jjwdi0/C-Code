#include <bits/stdc++.h>
using namespace std;

int A, B, C, D, E;

int main() {
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    printf("%d\n", max(0, -A) * C + (A < 0) * D + (B - max(A, 0)) * E);
}

