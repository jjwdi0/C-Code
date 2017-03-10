#include <stdio.h>
#include <string.h>

char A[1000003];
int J, O, I, ans, N;
int max(int X, int Y){ return X > Y ? X : Y; }

int main() {
	scanf("%s", A);
	N = strlen(A);
	if(A[0] == 'J') J++;
	if(A[0] == 'O') O++;
	if(A[0] == 'I') I++;
	for(int i=1; i<N; i++) {
		if(A[i] == 'J') {
			if(A[i-1] == 'J') J++;
			else { if(A[i-1] == 'O') O = 0; J = 1; }
		}
		else if(A[i] == 'O') {
			if(A[i-1] == 'O') O++;
			else { if(A[i-1] != 'J') J = 0; O = 1; }
		}
		else if(A[i] == 'I') {
			if(A[i-1] == 'I') I++;
			else { if(A[i-1] == 'J') J = 0; I = 1; }
			if(O == I && J >= O) ans = max(ans, O);
		}
	}
	printf("%d", ans);
}
