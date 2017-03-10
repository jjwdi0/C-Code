#include <stdio.h>

int W, H, N, prex, prey, cnt;

int min(int X, int Y) { return X > Y ? Y : X; }
int max(int X, int Y) { return X > Y ? X : Y; }

int main() {
	scanf("%d %d %d", &W, &H, &N);
	for(int i=0, x, y; i<N; i++) {
		scanf("%d %d", &x, &y);
		if(!i) prex = x, prey = y;
		else {
			if(prex <= x && prey <= y) cnt += max(x - prex, y - prey);
			else if(prex > x && prey > y) cnt += max(prex - x, prey - y);
			else if(prex > x && prey <= y) cnt += prex - x + y - prey;
			else cnt += x - prex + prey - y;
			prex = x, prey = y;
		}
	}
	printf("%d", cnt);
}
