#include <stdio.h>

int N, I, IO, IOI, cnt;
char A[1000005];

int main() {
	scanf("%d\n%s", &N, A);
	for(int i=0; i<N; i++) {
		if(A[i] == 'J') I++;
		else if(A[i] == 'O') {
			if(I > 0) I--, IO++;
			else if(IOI > 0) IOI--, cnt += 2, IO += 2;
		}
		else if(A[i]=='I') {
			if(IO > 0) {
				IO--;
				if(IO == cnt - 1) cnt--;
				IOI++;
			}
			else I++;
		}
	}
	printf("%d", IOI + cnt / 2);
}
