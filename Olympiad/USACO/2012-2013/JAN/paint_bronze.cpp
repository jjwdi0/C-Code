#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;
int N, xpos;

int main() {
	scanf("%d", &N);
	for(int i=0, x; i<N; i++) {
		char y;
		scanf("%d %c", &x, &y);
		if(y == 'L') {
			m[xpos + 1]--;
			m[xpos - x]++;
			xpos -= x;
		}
		else {
			m[xpos]++;
			m[xpos + x + 1]--;
			xpos += x;
		}
	}
	bool flag = false;
	int cnt = 0, ans = 0, pre;
	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cnt += it -> second;
		if(cnt >= 2 && !flag) flag = true, pre = it -> first;
		else if(cnt < 2 && flag) flag = false, ans += it -> first - pre - 1;
	}
	printf("%d", ans);
}
