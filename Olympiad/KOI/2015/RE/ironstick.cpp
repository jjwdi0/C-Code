#include <stdio.h>
#include <string.h>

char A[100005];
int k, p, l;

int main() {
	scanf("%s", A);
	l = strlen(A);
	for(int i=1; i<l; i++) {
		if(A[i] == '(') k++;
		else if(A[i-1] == '(') p += k, k--;
		else k--, p++;
	}
	printf("%d", p);
}
