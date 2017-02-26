#include <stdio.h>
#include <set>
using namespace std;

int N, K, A[1111][2], ans;
multiset<int> s;

int get_ans() {
	int mon = K, cnt = 0;
	for(auto it : s) {
		if(mon < it) return cnt;
		mon -= it, cnt++;
	}
	return cnt;
}

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d %d", &A[i][0], &A[i][1]), s.insert(A[i][0] + A[i][1]);
	for(int i=0; i<N; i++) {
		auto it = s.find(A[i][0] + A[i][1]);
		s.erase(it);
		s.insert(A[i][0] / 2 + A[i][1]);
		ans = max(ans, get_ans());
		it = s.find(A[i][0] / 2 + A[i][1]);
		s.erase(it);
		s.insert(A[i][0] + A[i][1]);
	}
	printf("%d", ans);
}
