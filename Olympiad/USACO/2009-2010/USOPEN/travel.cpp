#include <stdio.h>

int par[80003], rec[80003] = {-1}, N;

int main() {
	scanf("%d", &N);
	for(int i=1, x; i<=N; i++) {
		char q;
		scanf(" %c", &q);
		if(q == 'a') {
			par[i] = i - 1;
			scanf("%d", &x);
			rec[i] = x;
		}
		else if(q == 's') {
			rec[i] = rec[par[i - 1]];
			par[i] = par[par[i - 1]];
		}
		else if(q == 't') {
			scanf("%d", &x);
			rec[i] = rec[x - 1];
			par[i] = par[x - 1];
		}
		printf("%d\n", rec[i]);
	}
}
