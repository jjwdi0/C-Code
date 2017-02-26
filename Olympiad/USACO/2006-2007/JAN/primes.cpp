#include <stdio.h>

int A, B, C, cnt;
bool chk[4000005];

bool isthere(int x) {
	while(x) {
		if(x % 10 == C) return 1;
		x /= 10;
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	for(int i=2; i*i<=4000000; i++) {
		if(chk[i]) continue;
		for(int j=i*i; j<=4000000; j+=i) chk[j]=1;
	}
	for(int i=A; i<=B; i++) if(!chk[i]) cnt += isthere(i);
	printf("%d", cnt);
}
