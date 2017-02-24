#include "scrivener.h"

int par[1<<20][21], size[1<<20], for_undo[1<<20],  kth, Q;
char a[1<<20];

void Init(){}

void TypeLetter(char x) {
	for_undo[kth] = kth; if(kth) par[kth][0] = for_undo[kth - 1]; 
	for(int i = 1; par[kth][i-1]; i++) par[kth][i] = par[par[kth][i-1]][i-1];
	a[kth] = x, size[kth] = size[par[kth++][0]] + 1;
}

void UndoCommands(int x){ for_undo[kth] = for_undo[kth++ - x - 1]; }

char GetLetter(int x) {
	int u = for_undo[kth - 1];
	for(int i = 19; ~i; i--) if(size[par[u][i]] > x) u = par[u][i];
	return a[u];
}
