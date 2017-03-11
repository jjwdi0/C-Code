#include <bits/stdc++.h>
using namespace std;

string A[13];
int N, K;
set<string> s;

int main() {
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++) cin >> A[i];
	sort(A, A + N);
	do {
		string t = "";
		for(int j=0; j<k; j++) t = t + A[j];
		s.insert(t);
	}while(next_permutation(A, A + N));
	printf("%d", s.size());
}
