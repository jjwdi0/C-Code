#include <stdio.h>

int A[1002][1002], N, x, y, dir, cnt;
int d[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void f(int p, int q) {
	if(cnt == N - 1) { printf("%d %d", p, q); return; }
	if((dir & 1 ? (p == x) : (q == y)) || A[p + d[dir][0]][q + d[dir][1]]) dir = (dir + 1) % 4, f(p, q);
	else {
		A[p][q]++;
		cnt++;
		f(p + d[dir][0], q + d[dir][1]);
	}
}

int main() {
	scanf("%d %d %d", &x, &y, &n);
	if(n > x * y) printf("0");
	else f(1, 1);
}
