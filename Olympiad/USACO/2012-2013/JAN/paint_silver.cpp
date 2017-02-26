#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;
int N, K, xpos;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0, x; i<N; i++) {
		char y;
		scanf("%d %c", &x, &y);
		if(y == 'L') {
			m[xpos]--;
			m[xpos - x]++;
			xpos -= x;
		}
		else {
			m[xpos]++;
			m[xpos + x]--;
			xpos += x;
		}
	}
	bool flag = false;
	int cnt = 0, ans = 0, pre;
	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cnt += it -> second;
		if(cnt >= K && !flag) flag = true, pre = it -> first;
		else if(cnt < K && flag) flag = false, ans += it -> first - pre;
	}
	printf("%d", ans);
}
