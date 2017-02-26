#include <stdio.h>
#include <algorithm>
#define MAX_N 5003
using namespace std;

int N, A[MAX_N], D[MAX_N][MAX_N];

int f(int S, int E) {
	if(D[S][E]) return D[S][E];
	if(S > E) return 0;
	return D[S][E] = max(min(f(S + 1, E - 1), f(S + 2, E)) + A[S], min(f(S + 1, E - 1), f(S, E - 2)) + A[E]);
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", A + i);
	printf("%d", f(0, N - 1));
}
