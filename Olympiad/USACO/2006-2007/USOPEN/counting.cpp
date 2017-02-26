#include <stdio.h>

int N, L;

bool f(int x) {
	while(x) {
		if(x % 10 == L) return false;
		x /= 10;
	}
	return true;
}

int main() {
	scanf("%d %d", &N, &L);
	for(int i=1, j=1; i<=N; j++) {
		i += f(j);
		if(i == N + 1) return printf("%d", j),0;
	}
}
