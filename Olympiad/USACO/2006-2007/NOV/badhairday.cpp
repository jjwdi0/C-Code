#include<stdio.h>
#include <stack>
using namespace std;

struct data{
	int num, index;
};

stack <data> s;
int n, t;
long long cnt;

int main() {
	scanf("%d", &n);
	s.push({0, -1});
	for(int i=0; i<n; i++) {
		scanf("%d", &t);
		while(!s.empty()) {
			if(s.top().num <= t) {
				cnt += (long long)(i - s.top().index - 1);
				s.pop();
				continue;
			}
			s.push({t, i}); break;
		}
		if(s.empty()) s.push({t, i});
	}
	t = 2e9;
	while(!s.empty()) {
		if(s.top().num <= t){
			cnt += (i - s.top().index - 1);
			s.pop();
			continue;
		}
		s.push({t, i});
	}
	printf("%lld", cnt);
}
