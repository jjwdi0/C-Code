#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> m;
int N, K;

int f(int x) {
	if(m[x]) return m[x];
	if(x % 2 != K % 2 || x <= K) return 1;
	int t1 = x / 2 - K / 2, t2 = x - t1;
	return m[x] = f(t1) + f(t2);
}

int main() {
	scanf("%d %d", &N, &K);
	printf("%d", f(N));
}
