#include <stdio.h>
#include <stdlib.h>

struct rect { int x1, y1, x2, y2; } rect1, rect2;
int x[4], y[4];
int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
bool is_overlap(int a, int b, int c, int d) { return !(b <= c || d <= a); }

int main() {
	int res;
	for(int t=0; t<4; t++) {
		scanf("%d %d %d %d %d %d %d %d", &rect1.x1, &rect1.y1, 
		&rect1.x2, &rect1.y2, &rect2.x1, &rect2.y1, 
		&rect2.x2, &rect2.y2);
		x[0] = rect1.x1, x[1] = rect1.x2, x[2] = rect2.x1, x[3] = rect2.x2;
		y[0] = rect1.y1, y[1] = rect1.y2, y[2] = rect2.y1, y[3] = rect2.y2;
		qsort(x, 4, sizeof(x[0]), comp);
		qsort(y, 4, sizeof(y[0]), comp);
		res = -1;
		for(int i=0; i<3; i++) {
			if(x[i] == x[i+1]) continue;
			for(int j=0; j<3; j++) {
				if(y[j] == y[j+1]) continue;
				if(rect1.x1 <= x[i] && x[i+1] <= rect1.x2 && 
				rect1.y1 <= y[j] && y[j+1] <= rect1.y2 && 
				rect2.x1 <= x[i] && x[i+1] <= rect2.x2 && 
				rect2.y1 <= y[j] && y[j+1] <= rect2.y2) res = 0;
			}
		}
		if(res == 0) {
			puts("a");
			continue;
		}
		if((rect1.x2 == rect2.x1 && rect1.y2 == rect2.y1) || 
		(rect1.x2 == rect2.x1 && rect1.y1 == rect2.y2) || 
		(rect1.x1 == rect2.x2 && rect1.y1 == rect2.y2) || 
		(rect1.x1 == rect2.x2 && rect1.y2 == rect2.y1)) {
			puts("c");
			continue;
		}
		if((rect1.y1 == rect2.y2 && 
		is_overlap(rect1.x1, rect1.x2, rect2.x1, rect2.x2)) || 
		(rect1.y2 == rect2.y1 && 
		is_overlap(rect1.x1, rect1.x2, rect2.x1, rect2.x2)) || 
		(rect1.x2 == rect2.x1 && 
		is_overlap(rect1.y1, rect1.y2, rect2.y1, rect2.y2)) || 
		(rect1.x1 == rect2.x2 && 
		is_overlap(rect1.y1, rect1.y2, rect2.y1, rect2.y2))) {
			puts("b");
			continue;
		}
		puts("d");
	}
}
