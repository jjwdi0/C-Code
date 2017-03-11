#include <stdio.h>
#include <algorithm>
using namespace std;

int A[12], B[12], N = 10;

int main() {
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<N; i++) scanf("%d", B+i);
	sort(A, A+N);
	sort(B, B+N);
	printf("%d %d", A[9] + A[8] + A[7], B[9] + B[8] + B[7]);
}
