#include <stdio.h>
#include <string.h>

char a[50005];
int cnt, cnt2 = 1, cnt3;

int main() {
	scanf("%s", a);
	int len = strlen(a);
	a[len] = '(';
	for(int i=1; i<=len; i++) {
		if(a[i]==')' && a[i-1]=='(') cnt3 += (cnt2 - 1), cnt2 = 1;
		else if(a[i] == '(' && a[i-1] == ')') cnt += (cnt3 * (cnt2 - 1)), cnt2 = 1;
		else cnt2++;
	}
	printf("%d\n", cnt);
}
