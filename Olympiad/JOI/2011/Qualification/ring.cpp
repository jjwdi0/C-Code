#include <stdio.h>
#include <string.h>

int N, ans;
char A[13], B[13];

int main() {
	scanf("%s\n%d", A, &N);
	for(int i=0; i<N; i++) {
		scanf("%s", B);
		for(int i=0; i<10; i++) {
			int cnt = 0;
			for(int j=i; j<i+10; j++) if(A[j-i] == B[j%10]) cnt++;
			if(cnt == strlen(B)) { ans++; break; }
		}
	}
	printf("%d", ans);
}
