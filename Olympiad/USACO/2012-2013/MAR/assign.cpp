#include <stdio.h>

int N, Q, A[16], T[53][2], ans;
int adj[53][53];
char P[53];

void f(int x) {
	if(x == N) {
		ans++; return;
	}
	for(int i=0; i<3; i++) {
		A[x] = i;
		bool c = true;
		for(int j=0; j<x && c; j++) if(adj[x][j]) {
			if(A[x] == A[j] && adj[x][j] == 2) c = false;
			if(A[x] != A[j] && adj[x][j] == 1) c = false;
		}
		if(c) f(x + 1);
	}
}

int main() {
	scanf("%d %d", &N, &Q);
	for(int i=0; i<Q; i++) scanf(" %c %d %d", P+i, T[i], T[i]+1), T[i][0]--, T[i][1]--, adj[T[i][0]][T[i][1]] = adj[T[i][1]][T[i][0]] = (P[i] == 'S' ? 1 : 2);
	f(0);
	printf("%d\n", ans);
}
