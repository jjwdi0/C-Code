#include <stdio.h>
#include <algorithm>
using namespace std;

struct data{ int num, A_i, B_i; } T[1003];
int N, M;
bool cmp1(const data &x, const data &y) { return x.A_i < y.A_i; }
bool cmp2(const data &x, const data &y) { return x.B_i > y.B_i; }

int main() {
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", &T[i].A_i), T[i].num = i;
	while(M--) {
		int t;
		scanf("%d", &t);
		for(int i=1; i<=N; i++) {
			if(T[i].A_i <= t) {
				T[i].B_i++;
				break;
			}
		}
	}
	sort(T + 1, T + N + 1, cmp2);
	printf("%d", T[1].num);
}
