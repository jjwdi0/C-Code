#include <stdio.h>

int N, Q;
bool chk[10005];

int main() {
	scanf("%d %d", &N, &Q);
	for(int i=0, x, y; i<Q; i++) {
		scanf("%d %d", &x, &y);
		for(int j=x; j<=N; j+=y) chk[j] = 1;
	}
	int cnt = 0;
	for(int i=1; i<=N; i++) cnt += !chk[i];
	printf("%d\n", cnt);
}
