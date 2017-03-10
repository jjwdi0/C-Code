#include <stdio.h>

int a[103][3], game[205][3], n, score[205];

void find(int num, int order) {
	for(int i=0; i<n; i++) {
		if(game[i][order] == num) {
			score[i] += num;
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) for(int j=0; j<3; j++) {
		scanf("%d", &game[i][j]);
		a[game[i][j]][j]++;
	}
	for(int i=0; i<3; i++) for(int j=0; j<=100; j++) if(a[j][i] == 1) find(j, i);
	for(int i=0; i<n; i++) printf("%d\n", score[i]);
}
