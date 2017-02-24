#include <stdio.h>

int N, S, E, ans = 2e9;
int min(int X, int Y){ return X>Y?Y:X; }

int main() {
	scanf("%d", &N);
	for(int i = 1, x; i <= N; i++) {
		scanf("%d", &x);
		if(i == 1) { S = x; continue; }
		if(i == 2) E = x;
		E = min(E, x);
		if(S > x) return puts("0"), 0;
		S = 2 * x - S, E = 2 * x - E; S ^= E ^= S ^= E;
	}
	printf("%d", E - S + 1);
}
