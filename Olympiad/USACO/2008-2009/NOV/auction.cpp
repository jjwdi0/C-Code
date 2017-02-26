#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M, A[1003], ans, cost;

int main() {
	scanf("%d %d", &M, &N);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	sort(A, A+N);
	for(int i=0; i<N; i++) {
		if(ans < A[i] * min(M, N - i)) ans = A[i] * min(M, N - i), cost = A[i];
	}
	printf("%d %d", cost, ans);
}
