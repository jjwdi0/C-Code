#include <stdio.h>
#include <cstring>

char board[30], temp[103];
int n, cnt;

bool find(int x) {
	for(int i=x+1; i<strlen(temp); i++) {
		if(board[1] == temp[i]) {
			int det = 0, k = 1;
			for(int j=i; j<strlen(temp); k++, j+=i-x) {
				if(board[k] == temp[j]) det++;
				else break;
			}
			if(det == strlen(board) - 1) return true;
		}
	}
	return false;
}

int main() {
	scanf("%d\n%s", &n, board);
	while(n--) {
		scanf("%s", temp);
		for(int i=0; i<strlen(temp); i++) {
			if(temp[i] == board[0]) {
				if(find(i)) {
					cnt++;
					break;
				}
			}
		}
	}
	printf("%d", cnt);
}
