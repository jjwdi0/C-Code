#include <stdio.h>
#include <algorithm>
using namespace std;

struct Z {
	int x, y, z;
	bool operator < (const Z &a) const {
		return y == a.y ? x > a.x : y < a.y;
	}
};

int N, C, M, sto[2002], ans;
Z A[10005];

int main() {
	scanf("%d %d %d", &N, &C, &M);
	for(int i=0; i<M; i++) scanf("%d %d %d", &A[i].x, &A[i].y, &A[i].z);
	sort(A, A+M);
	for(int i=0; i<M; i++) {
		int add = A[i].z;
		for(int j=A[i].x; j<A[i].y; j++) add = min(add, C - sto[j]);
		for(int j=A[i].x; j<A[i].y; j++) sto[j] += add;
		ans += add;
	}
	printf("%d\n", ans);
}
