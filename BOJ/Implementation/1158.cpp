#include <stdio.h>
#include <queue>
using namespace std;

queue<int> q;
int cnt, N, K, ans[5005], r;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=1; i<=N; i++) q.push(i);
	while(!q.empty()) {
		cnt++;
		if(cnt == K) {
			ans[r++] = q.front();
			cnt = 0;
		}
		else q.push(q.front());
		q.pop();
	}
	printf("<");
	for(int i=0; i<r-1; i++) printf("%d, ", ans[i]);
	printf("%d>", ans[r-1]);
}
