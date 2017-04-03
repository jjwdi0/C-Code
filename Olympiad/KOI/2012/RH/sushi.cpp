#include <stdio.h>

int max(int x, int y) { return x > y ? x : y; }
int N, A[30005], B[3005], k, c, d, cnt, m;

int f(int x, int y) {
	if(x == 0) {
		for(int p=x; p<=y; B[A[p]]++,p++) if(B[A[p]] == 0) cnt++;
		return cnt;
	}
	if(B[A[x-1]] == 1) cnt--;
	B[A[x-1]]--;
	if(B[A[y]] == 0) cnt++;
	B[A[y]]++;
	return cnt;
}

int main() {
	scanf("%d %d %d %d", &N, &d, &k, &c);
	B[c]++;
	cnt++;
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=0; i<N; i++) m = max(m, f(i, (i + k - 1) % N));
	printf("%d", m);
}
