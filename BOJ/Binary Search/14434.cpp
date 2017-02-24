#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;

int N, M, K, Q, A[200005], B[200005];
pr T[200005];
int output[200005];

int f(int pos, int val) {
	return upper_bound(T+1, T+K+1, pr(val, pos)) - lower_bound(T+1, T+K+1, pr(val, 1));
}

int main() {
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for(int i=1; i<=M; i++) scanf("%d", A+i); 
	for(int i=1; i<=K; i++) scanf("%d", B+i), T[i] = pr(B[i], i);
	sort(T+1, T+K+1);
	for(int i=1, x, y, z; i<=Q; i++) {
		scanf("%d %d %d", &x, &y, &z);
		int lo = 0, hi = K;
		while(lo <= hi) {
			int mid = lo + hi >> 1;
			f(mid, x) + f(mid, y) >= A[z] ? hi = mid - 1 : lo = mid + 1;
		}
		output[lo]++;
	}
	for(int i=1; i<=K; i++) {
		output[i] += output[i-1];
		printf("%d\n", output[i]);
	}
}