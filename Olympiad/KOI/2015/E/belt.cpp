#include<cstdio>

int k=1, ans, N;

int main() {
	scanf("%d",&N);
	for(int i=0, x, y, z; i<N; i++) {
		scanf("%d %d %d", &x, &y, &z);
		k = k * y / x;
		ans += z;
	}
	printf("%d %d", ans % 2, k);
}
