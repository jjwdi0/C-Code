#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll>>q;
int n;
ll t;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%lld", &t);
		q.push(t);
	}
	ll cnt = 0;
	while(q.size() - 1) {
		ll t1 = q.top(); q.pop();
		ll t2 = q.top(); q.pop();
		cnt += t1 + t2;
		q.push(t1 + t2);
	}
	printf("%lld", cnt);
}
