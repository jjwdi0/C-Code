#include <stdio.h>

int T, x1, y1, x2, y2, n, cx, cy, r, count = 0;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);
		for(int j=0; j<n ; j++) {
			scanf("%d %d %d", &cx, &cy, &r);
			if((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) >= r * r
			|| (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) >= r * r) {   
				if((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) < r * r) count++;
				if((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) < r * r) count++;
			}
		}
    	printf("%d\n", count);
    	count = 0;
	}
}
