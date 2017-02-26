#include <stdio.h>
#include <algorithm>
using namespace std;

int N, S, A[22222], ans;

int main() {
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	sort(A, A+N);
	for(int i=0; i<N; i++) ans += max(0, (int)(upper_bound(A+i+1, A+N, S-A[i]) - lower_bound(A+i+1, A+N, 0)));
	printf("%d", ans);
}
