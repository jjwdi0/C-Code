#include <stdio.h>

int a, b, c, t[3][100];

int main() {
	scanf("%d %d %d", &a, &b, &c);
	for(int i=1; i<=a; i++) t[0][i]++;
	for(int i=1; i<=a; i++) for(int j=1; j<=b; j++) t[1][i+j] += t[0][i];
	for(int i=1; i<=a+b; i++) for(int j=1; j<=c; j++) t[2][i+j] += t[1][i];
	int ans = 0;
	for(int i=0; i<=a+b+c; i++) if(ans < t[2][i]) ans = t[2][i];
	for(int i=0; i<=a+b+c; i++) if(ans == t[2][i]) return printf("%d", i),0;
}
