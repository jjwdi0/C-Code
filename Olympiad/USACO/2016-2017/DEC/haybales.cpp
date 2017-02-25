#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A[100003], Q;

int main() {
	scanf("%d %d", &N, &Q);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	sort(A, A+N);
	while(Q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", upper_bound(A, A+N, y) - lower_bound(A, A+N, x));
	}
}
