#include <stdio.h>

int a[6][3], b[6][3], det, cnt;

void f(int x, int y) {
	if(det) return;
	if(y == 6) { if(a[x][0]!=b[x][0] || a[x][1]!=b[x][1] || a[x][2]!=b[x][2]) return; f(x+1, 0); return; }
	if(x == 6) { det = 1; return; }
	if(x >= y) { f(x, x + 1); return; }
	else {
		a[x][0]++, a[y][2]++, f(x, y + 1), a[x][0]--, a[y][2]--;
		a[x][1]++, a[y][1]++, f(x, y + 1), a[x][1]--, a[y][1]--;
		a[x][2]++, a[y][0]++, f(x, y + 1), a[x][2]--, a[y][0]--;
	}
}

int main() {
	for(int i=0; i<4; i++) {
		cnt = det = 0;
		for(int j=0; j<18; j++) scanf("%d", &b[j / 3][j % 3]);
		f(0, 0);
		printf("%d ", det);
	}
}
