#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
pair<int, int> A[1005];

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
	return x.second < y.second;
}

int main() {
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d %d", &A[i].first, &A[i].second);
	sort(A, A+N, cmp);
	int cnt = 0, ans = 1987654321;
	for(int i=0; i<N; i++) {
		cnt += A[i].first;
		ans = min(ans, A[i].second - cnt);
	}
	printf("%d", max(-1, ans));
}
