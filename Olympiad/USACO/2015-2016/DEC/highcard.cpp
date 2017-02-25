#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A[50003], B[50003], ans;
bool isinput[100005];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", A + i), isinput[A[i]] = true;
	sort(A, A + N);
	for(int i = 1, k = 0; i <= 2 * N; i++) if(!isinput[i]) B[k++] = i;
	for(int i = 0, j = 0; i < N && j < N; j++, i++) {
		while(B[j] < A[i]) j++;
		ans++;
	}
	printf("%d", ans);
}
