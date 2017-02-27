#include <stdio.h>
#include <deque>
using namespace std;

deque<int> dq;
int N, M, A[53], ans;

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++) scanf("%d", A+i);
	for(int i=1; i<=N; i++) dq.push_back(i);
	for(int i=0; i<M; i++) {
		int cnt = 0;
		while(dq.front() != A[i]) {
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
		if(cnt > dq.size() / 2) cnt = dq.size() - cnt;
		ans += cnt;
		dq.pop_front();
	}
	printf("%d", ans);
}
