#include <stdio.h>
#include <algorithm>
using namespace std;

int N, s[200005], total;
int size[200005], color[200005], cnt;

struct Z {
	int size, color, idx, sum;
}A[200005];

bool cmp(const Z &x, const Z &y){ return x.size < y.size; }
bool cmp2(const Z &x, const Z &y){ return x.idx < y.idx; }

int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d %d", &A[i].color, &A[i].size);
		A[i].idx = i;
	}
	sort(A + 1, A + N + 1, cmp);
	for(int i=1; i<=N; i++) {
		if(A[i].size != A[i-1].size) {
			for(int j=1; j<=cnt; j++) s[color[j]] += size[j], total += size[j];
			cnt = 0;
		}
		cnt++;
		size[cnt] = A[i].size;
		color[cnt] = A[i].color;
		A[i].sum = total - s[A[i].color];
	}
	sort(A + 1, A + N + 1, comp2);
	for(int i=1; i<=N; i++) printf("%d\n", A[i].sum);
}
