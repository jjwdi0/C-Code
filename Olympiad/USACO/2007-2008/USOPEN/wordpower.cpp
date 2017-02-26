#include <bits/stdc++.h>
using namespace std;

int N, M, score[1003];
string S1[1003], S2[100];

bool isgood(int x, int y) {
	int i = 0, j = 0;
	while(i < S1[x].length() && j < S2[y].length()) {
		if(S1[x][i] == S2[y][j]) i++, j++;
		else i++;
	}
	return j == S2[y].length();
}

string make_small(string x) {
	for(int i=0; i<x.length(); i++) if(x[i] <= 'Z' && x[i] >= 'A') x[i] = x[i] - 'A' + 'a';
	return x;
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) cin >> S1[i], S1[i] = make_small(S1[i]);
	for(int i=0; i<M; i++) cin >> S2[i], S2[i] = make_small(S2[i]);
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) score[i] += (isgood(i, j));
	for(int i=0; i<N; i++) printf("%d\n", score[i]);
}
