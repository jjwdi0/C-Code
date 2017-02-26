#include <stdio.h>

int hash_table[10005], n, cnt;

int main() {
	scanf("%d", &n);
	for(;; n=t) {
		hash_table[n]++;
		int t = ((n / 100) % 10) * 10 + ((n / 10) % 10);
		t *= t;
		cnt++;
		if(hash_table[t] == 1) {
			printf("%d", cnt);
			return 0;
		}
	}
}
