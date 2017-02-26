#include <stdio.h>
#include <algorithm>
using namespace std;

double A[555], cnt;
int N;

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lf", A+i), cnt+=A[i];
	printf("%.6f\n", cnt / (double)N);
	sort(A, A+N);
	printf("%.6f", N & 1 ? A[N/2] : (A[N/2-1] + A[N/2]) / 2.0);
}
