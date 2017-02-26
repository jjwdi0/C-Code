#include <stdio.h>

int n, a[103][3];

int chk(int x, int y) {
	int strike = 0, ball = 0;
	int d1 = x / 1000, d2 = (x / 100) % 10, d3 = (x / 10) % 10, d4 = x % 10;
	int t1 = a[y][0] / 1000, t2 = (a[y][0] / 100) % 10, t3 = (a[y][0] / 10) % 10, t4 = a[y][0] % 10;
	if(d1 == t1) strike++,d1 = t1 = -1;
	if(d2 == t2) strike++,d2 = t2 = -1;
	if(d3 == t3) strike++,d3 = t3 = -1;
	if(d4 == t4) strike++, d4 = t4 = -1;
	if(d1 >= 0 && t1 >= 0) if(d1 == t2) ball++; else if(d1 == t3) ball++; else if(d1 == t4) ball++;
	if(d2 >= 0 && t2 >= 0) if(d2 == t1) ball++; else if(d2 == t3) ball++; else if(d2 == t4) ball++;
	if(d3 >= 0 && t3 >= 0) if(d3 == t2) ball++; else if(d3 == t1) ball++; else if(d3 == t4) ball++;
	if(d4 >= 0 && t4 >= 0) if(d4 == t2) ball++; else if(d4 == t3) ball++; else if(d4 == t1) ball++;
	return strike == a[y][1] && ball == a[y][2];
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	for(int i=1000; i<10000; i++) {
		int cnt = 0;
		for(int j=0; j<n; j++) cnt += chk(i, j);
		if(cnt == n) return !printf("%d", i);
	}
	puts("NONE");
}
