#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int Q, N, M, sum, A[2222], B[2222], D[151515][2];
bool flag;

int main() {
	scanf("%d %d %d", &Q, &N, &M);
	for(int i=0; i<N; i++) scanf("%d", A+i), sum += A[i];
	for(int i=0; i<M; i++) scanf("%d", B+i);
	D[0][0] = D[0][1] = 1;
	if(sum >= Q) {
		for(int i=0; i<N; i++) for(int j=0; j<=Q; j++) {
			if(D[j][i&1]) {
				if(j + A[i] <= Q) D[j + A[i]][(i+1)&1] = 1;
				if(j + A[i] == Q) flag = true;
			}
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag) return printf("%d", Q),0;
	sort(A, A+N, greater<int>());
	sort(B, B+M, greater<int>());
	int ans = 0, cnt = 0;
	for(int i=0; i<N && Q; i++) {
		if(Q < A[i]) {
			cnt += Q - 1;
			for(int j=0; j<N; j++) if(A[j] == Q) { cnt++; break; }
			ans = max(ans, cnt);
			Q = 0;
		}
		else {
			cnt += A[i];
			Q -= A[i];
			int t = Q, c1 = 0;
			for(int j=0; t && j<N; j++) {
				if(t < B[j]) c1 += t - 1, t = 0;
				else c1 += B[j] - 1, t -= B[j];
			}
			ans = max(ans, cnt + c1);
		}
	}
	printf("%d", ans);
}
