#include <bits/stdc++.h>

int N, Q, A[50003];

int main() {
	scanf("%d %d", &N, &Q);
	for(int i=1; i<=N; i++) scanf("%d", A+i), A[i] += A[i-1];
	for(int i=0, x; i<Q; i++) scanf("%d", &x), printf("%d\n", std::upper_bound(A, A + N, x) - A);
}
