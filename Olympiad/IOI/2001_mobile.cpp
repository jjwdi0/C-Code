#include <cstdio>

struct BIT {
	int T[1050][1050], B;
	void init(int x){ B = x + 2; }
	void add(int x, int y, int v) {
		x += 2,y += 2;
		int _x = x;
		while(y <= B) {
			while(x <= B) T[x][y] += v, x += x & -x;
			x = _x; y += y & -y;
		}
	}
	int q(int x, int y) {
		x += 2, y += 2;
		int _x = x, res = 0;
		while(y) {
			while(x) res += T[x][y], x -= x & -x;
			x = _x; y -= y & -y;
		}
		return res;
	}
}bit;

int main() {
	for(int q=0; q!=3;) {
		scanf("%d",&q);
		if(q == 0) {
			int x;
			scanf("%d",&x);
			bit.init(x);
		}
		if(q == 1) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			bit.add(x, y, z);
		}
		if(q == 2) {
			int x, y, z, w;
			scanf("%d %d %d %d", &x, &y, &z, &w);
			printf("%d\n", bit.q(z, w) - bit.q(z, y - 1) - bit.q(x - 1, w) + bit.q(x - 1, y - 1));
		}
	}
} 
