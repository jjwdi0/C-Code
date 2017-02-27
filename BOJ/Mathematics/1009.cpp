#include <stdio.h>

int n, a, b;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d %d", &a, &b);
		a = (a - 1) % 10 + 1;
		if(a == 10 || a == 1 || a == 5 || a == 6) printf("%d\n", a);
		else if(a == 2) {
			if(b % 4 == 1) puts("2");
			if(b % 4 == 2) puts("4");
			if(b % 4 == 3) puts("8");
			if(b % 4 == 0) puts("6");
		}
		else if(a == 3) {
			if(b % 4 == 1) puts("3");
			if(b % 4 == 2) puts("9");
			if(b % 4 == 3) puts("7");
			if(b % 4 == 0) puts("1");
		}
		else if(a == 7) {
			if(b % 4 == 1) puts("7");
			if(b % 4 == 2) puts("9");
			if(b % 4 == 3) puts("3");
			if(b % 4 == 0) puts("1");
		}
		else if(a == 8) {
			if(b % 4 == 1) puts("8");
			if(b % 4 == 2) puts("4");
			if(b % 4 == 3) puts("2");
			if(b % 4 == 0) puts("6");
		}
		else if(a == 9) {
			if(b % 2 == 1) puts("9");
			if(b % 2 == 0) puts("1");
		}
		else if(a == 4) {
			if(b % 2 == 1) puts("4");
			if(b % 2 == 0) puts("6");
		}
	}
}
