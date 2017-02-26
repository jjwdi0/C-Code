#include <stdio.h>
#include <algorithm>
using namespace std;

pair<int, int> A[100005];
int N, K, ans, cnt;
bool cmp(const pair<int, int> &x, const pair<int, int> &y) { return x.second < y.second; }

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d %d", &A[i].first, &A[i].second);
	sort(A, A+N, cmp);
	int i = 0, j = 1; cnt = A[0].first;
	while(i<N && j<=N) {
		if(A[j-1].second - A[i].second <= K * 2) ans = max(ans, cnt), cnt += A[j++].first;
		else cnt -= A[i++].first;
	}
	printf("%d\n", ans);
}
