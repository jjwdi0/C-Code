#include <stdio.h>

char t;
int cnt;

int main() {
	for(int i=0; i<8; scanf("%c", &t),i++) for(int j=0; j<8; j++) {
		scanf("%c", &t);
		if(t == 'F' && (i + j) % 2 == 0) cnt++;
	}
	printf("%d", cnt);
}
