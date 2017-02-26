#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
ll C, ans;
pair<ll, ll> T[100003];

int main() {
	scanf("%d %lld", &N, &C);
	for(int i=0; i<N; i++) scanf("%lld %lld", &T[i].first, &T[i].second);
	sort(T, T+N);
	for(int i=0; i<N; i++) {
		if(C / T[i].first < T[i].second) return !printf("%lld", ans + C / T[i].first);
		C -= T[i].first * T[i].second;
		ans += T[i].second;
	}
	printf("%lld", ans);
}
