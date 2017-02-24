#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

pr L[30005], R[30005];
int N, K, S, l_size, r_size, dist;

int main() {
	scanf("%d %d %d", &N, &K, &S);
	for(int i=0, x, y; i<N; i++)
	{
		scanf("%d %d", &x, &y);
		if(x > S) R[r_size++] = pr(x, y);
		else L[l_size++] = pr(x, y);
	}
	sort(L, L + l_size), sort(R, R + r_size, greater<pr>());
	int cap = 0, t = 0;
	for(int i=0; i<=l_size; i++)
	{
		if(i == l_size){ dist += t * 2; break; }
		if(!cap) t = S - L[i].first;
		if(L[i].second > K - cap) {
			dist += t * 2;
			L[i].second -= K - cap;
			i--, cap = 0;
		}
		else cap += L[i].second;
	}
	cap = t = 0;
	for(int i=0; i<=r_size; i++) {
		if(i == r_size){ dist += t * 2; break; }
		if(!cap) t = R[i].first - S;
		if(R[i].second > K - cap) {
			dist += t * 2;
			R[i].second -= K - cap;
			i--, cap = 0;
		}
		else cap += R[i].second;
	}
	printf("%d\n", dist);
}
