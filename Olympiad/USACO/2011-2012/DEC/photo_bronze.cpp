#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A[5][20005], B[20005];

bool cmp(const int &x, const int &y) {
	int cnt = 0;
	for(int i = 0; i < 5; i++) cnt += (A[i][x] < A[i][y]);
	return cnt >= 3;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < 5; i++) for(int j = 0, x; j < N; j++) scanf("%d", &x), A[i][x] = j;
	for(int i = 1; i <= N; i++) B[i] = i; sort(B + 1, B + N + 1, cmp);
	for(int i = 1; i <= N; i++) printf("%d\n", B[i]);
}
