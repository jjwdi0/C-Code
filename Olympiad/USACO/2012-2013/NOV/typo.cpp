#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int len, N, M, ans;
char A[100005];

int main() {
	scanf("%s", A);
	len = strlen(A);
	for(int i=0; i<len; i++) if(A[i] == '(') N++; else M++;
	if(N == M + 2) {
		for(int i=0; i<len; i++) A[i] = (A[i] == '(' ? ')' : '(');
		reverse(A, A+len);
	}
	N = M = 0;
	for(int i=0; i<len; i++) {
		if(A[i] == '(') N++; else M++;
		if(N < M - 2) return puts("0"),0;
		if(N == M - 1) { ans = M; break; }
	}
	printf("%d\n", ans);
}
